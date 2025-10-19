#include "ResourceManager.h"
#include <iostream>

// Set asset path here
const std::string ResourceManager::pathToBoardAtlas = "../../assets/custom chess assets/board/squares.png";
const std::string ResourceManager::pathToPieceAtlas = "../../assets/custom chess assets/pieces/pieces.png";

ResourceManager::ResourceManager() : boardSprite(boardAtlas), pieceSprite(pieceAtlas) {
    getAssets();
    setTextureRects();
};

void ResourceManager::draw(sf::RenderWindow& window, const Board& board, int TILE_SIZE) {
    for (int row = 0; row < Board::SIZE; ++row) {
        for (int col = 0; col < Board::SIZE; ++col) {
            sf::Vector2f currPos = {float(col) * TILE_SIZE, float(row) * TILE_SIZE};

            // Draw square
            bool isLightSqr = ((row + col) % 2 == 0);
            if (isLightSqr) {
                boardSprite.setTextureRect(lightSqrRect);
            }
            else {
                boardSprite.setTextureRect(darkSqrRect);
            }
            boardSprite.setPosition(currPos);
            boardSprite.setScale({float(TILE_SIZE) / SQUARE_SIZE, float(TILE_SIZE) / SQUARE_SIZE});
            window.draw(boardSprite);

            // Draw piece
            Piece* piece = board.getPieceAt({row, col});
            if (piece) {
                sf::IntRect rect = pieceRects[{piece->getType(), piece->getColor()}];
                pieceSprite.setTextureRect(rect);

                float scale = getAbsoluteScale(0.73f, TILE_SIZE);
                pieceSprite.setScale({scale, scale});

                sf::Vector2f scaledPieceSize = {rect.size.x * scale, rect.size.y * scale};
                pieceSprite.setPosition(getCenteredPos(currPos, scaledPieceSize, TILE_SIZE));

                window.draw(pieceSprite);
            }
        }
    }
}

#define SET_PIECE_RECT(type, color, row, x1, x2) \
    pieceRects[{PieceType::type, PieceColor::color}] = {{x1, row * SQUARE_SIZE}, {x2 - x1, SQUARE_SIZE}}

void ResourceManager::setTextureRects() {
    // Board
    lightSqrRect = {{0, 0}, {SQUARE_SIZE, SQUARE_SIZE}};
    darkSqrRect = {{0, SQUARE_SIZE}, {SQUARE_SIZE, SQUARE_SIZE}};

    // Row 0
    int currentX = 0;
    SET_PIECE_RECT(Pawn,   White, 0, currentX, currentX + PAWN_WIDTH); currentX += PAWN_WIDTH;
    SET_PIECE_RECT(Queen,  White, 0, currentX, currentX + QUEEN_WIDTH); currentX += QUEEN_WIDTH;
    SET_PIECE_RECT(King,   White, 0, currentX, currentX + KING_WIDTH); currentX += KING_WIDTH;
    SET_PIECE_RECT(Bishop, White, 0, currentX, currentX + BISHOP_WIDTH);
    // Row 1
    currentX = 0;
    SET_PIECE_RECT(Knight, White, 1, currentX, currentX + KNIGHT_WIDTH); currentX += KNIGHT_WIDTH;
    SET_PIECE_RECT(Rook,   White, 1, currentX, currentX + ROOK_WIDTH); currentX += ROOK_WIDTH;
    SET_PIECE_RECT(Pawn,   Black, 1, currentX, currentX + PAWN_WIDTH); currentX += PAWN_WIDTH;
    SET_PIECE_RECT(Queen,  Black, 1, currentX, currentX + QUEEN_WIDTH);
    // Row 2
    currentX = 0;
    SET_PIECE_RECT(King,   Black, 2, currentX, currentX + KING_WIDTH); currentX += KING_WIDTH;
    SET_PIECE_RECT(Bishop, Black, 2, currentX, currentX + BISHOP_WIDTH); currentX += BISHOP_WIDTH;
    SET_PIECE_RECT(Knight, Black, 2, currentX, currentX + KNIGHT_WIDTH); currentX += KNIGHT_WIDTH;
    SET_PIECE_RECT(Rook,   Black, 2, currentX, currentX + ROOK_WIDTH);

}

void ResourceManager::getAssets() {
    if (!pieceAtlas.loadFromFile(pathToPieceAtlas)) {
        std::cerr << "Failed to load piece atlas!\n";
    }
    if (!boardAtlas.loadFromFile(pathToBoardAtlas)) {
        std::cerr << "Failed to load board atlas!\n";
    }
}

float ResourceManager::getAbsoluteScale(float relativeScale, int TILE_SIZE) const {
    float baseScale = float(TILE_SIZE) / SQUARE_SIZE;
    float absoluteScale = baseScale * relativeScale;
    return absoluteScale;
}

sf::Vector2f ResourceManager::getCenteredPos(sf::Vector2f squarePos, sf::Vector2f textureRect, int TILE_SIZE) const {
    sf::Vector2f offset = {(TILE_SIZE - textureRect.x) / 2.0f, (TILE_SIZE - textureRect.y) / 2.0f};
    return (squarePos + offset);
}