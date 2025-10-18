#include "ResourceManager.h"
#include <iostream>

#define SET_PIECE_RECT(type, color, row, col) \
    pieceRects[{PieceType::type, PieceColor::color}] = {{SQUARE_SIZE * col, SQUARE_SIZE * row}, {SQUARE_SIZE, SQUARE_SIZE}}

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
                pieceSprite.setPosition(currPos);
                pieceSprite.setScale({float(TILE_SIZE) / SQUARE_SIZE, float(TILE_SIZE) / SQUARE_SIZE});
                window.draw(pieceSprite);
            }
        }
    }
}

void ResourceManager::setTextureRects() {
    // Board
    lightSqrRect = {{0, 0}, {SQUARE_SIZE, SQUARE_SIZE}};
    darkSqrRect = {{0, SQUARE_SIZE}, {SQUARE_SIZE, SQUARE_SIZE}};

    // White pieces
    SET_PIECE_RECT(Pawn,   White, 0, 0);
    SET_PIECE_RECT(Queen,  White, 0, 1);
    SET_PIECE_RECT(King,   White, 0, 2);
    SET_PIECE_RECT(Bishop, White, 0, 3);
    SET_PIECE_RECT(Knight, White, 1, 0);
    SET_PIECE_RECT(Rook,   White, 1, 1);

    // Black pieces
    SET_PIECE_RECT(Pawn,   Black, 1, 2);
    SET_PIECE_RECT(Queen,  Black, 1, 3);
    SET_PIECE_RECT(King,   Black, 2, 0);
    SET_PIECE_RECT(Bishop, Black, 2, 1);
    SET_PIECE_RECT(Knight, Black, 2, 2);
    SET_PIECE_RECT(Rook,   Black, 2, 3);

}

void ResourceManager::getAssets() {
    if (!pieceAtlas.loadFromFile(pathToPieceAtlas)) {
        std::cerr << "Failed to load piece atlas!\n";
    }
    if (!boardAtlas.loadFromFile(pathToBoardAtlas)) {
        std::cerr << "Failed to load board atlas!\n";
    }
}