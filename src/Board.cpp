#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

Board::Board() {
    setupDefaultBoard();
}

void Board::setupDefaultBoard() {
    // Place pawns
    for (int col = 0; col < SIZE; ++col) {
        grid[1][col] = std::make_unique<Pawn>(PieceColor::Black);
        grid[SIZE - 2][col] = std::make_unique<Pawn>(PieceColor::White);
    }

    // Place other pieces
    // Black
    grid[0][0] = std::make_unique<Rook>(PieceColor::Black);
    grid[0][1] = std::make_unique<Knight>(PieceColor::Black);
    grid[0][2] = std::make_unique<Bishop>(PieceColor::Black);
    grid[0][3] = std::make_unique<Queen>(PieceColor::Black);
    grid[0][4] = std::make_unique<King>(PieceColor::Black);
    grid[0][5] = std::make_unique<Bishop>(PieceColor::Black);
    grid[0][6] = std::make_unique<Knight>(PieceColor::Black);
    grid[0][7] = std::make_unique<Rook>(PieceColor::Black);
    
    // White
    grid[SIZE - 1][0] = std::make_unique<Rook>(PieceColor::White);
    grid[SIZE - 1][1] = std::make_unique<Knight>(PieceColor::White);
    grid[SIZE - 1][2] = std::make_unique<Bishop>(PieceColor::White);
    grid[SIZE - 1][3] = std::make_unique<Queen>(PieceColor::White);
    grid[SIZE - 1][4] = std::make_unique<King>(PieceColor::White);
    grid[SIZE - 1][5] = std::make_unique<Bishop>(PieceColor::White);
    grid[SIZE - 1][6] = std::make_unique<Knight>(PieceColor::White);
    grid[SIZE - 1][7] = std::make_unique<Rook>(PieceColor::White);
}

Piece* Board::getPieceAt(sf::Vector2i square) const {
    if (isWithinBoard(square)) {
        return grid[square.x][square.y].get();
    }
    return nullptr;
}

std::unique_ptr<Piece> Board::movePiece(sf::Vector2i src, sf::Vector2i dest) {
    enPassantTargetSquare.reset();

    if (!isWithinBoard(src) || !isWithinBoard(dest)) {
        return nullptr;
    }
    // Return nullptr if src is empty
    if (!grid[src.x][src.y]) {
        return nullptr;
    }

    std::unique_ptr<Piece> srcPiece = takePieceAt(src);
    std::unique_ptr<Piece> destPiece = takePieceAt(dest);

    // Update en passant state
    if (srcPiece->getType() == PieceType::Pawn && std::abs(src.x - dest.x) == 2) {
        int forward = (srcPiece->getColor() == PieceColor::Black ? 1 : -1);
        enPassantTargetSquare = src + sf::Vector2i{forward, 0};
    }

    placePieceAt(dest, std::move(srcPiece));
    grid[dest.x][dest.y]->hasMoved = true;

    // Return the ownership of the captured piece
    return destPiece;
}

std::unique_ptr<Piece> Board::takePieceAt(sf::Vector2i square) {
    if (!isWithinBoard(square)) {
        return nullptr;
    }
    return std::move(grid[square.x][square.y]);
}

void Board::placePieceAt(sf::Vector2i square, std::unique_ptr<Piece> piece) {
    if (!isWithinBoard(square)) {
        return;
    }
    grid[square.x][square.y] = std::move(piece);
}

bool Board::isValidMove(PieceColor srcColor, sf::Vector2i dest) const {
    if (isWithinBoard(dest)) {
        Piece* targetedSquare = getPieceAt(dest);
        // Cannot capture own piece
        if (targetedSquare && (targetedSquare->getColor() == srcColor)) {
            return false;
        }
        return true;
    }
    return false;
}

bool Board::isWithinBoard(sf::Vector2i square) const {
    return (square.x >= 0 && square.x < SIZE && square.y >= 0 && square.y < SIZE);
}

std::optional<sf::Vector2i> Board::getEnPassantTarget() const {
    return enPassantTargetSquare;
}