#include "Queen.h"
#include "Board.h"
#include "Rook.h"
#include "Bishop.h"

Queen::Queen(PieceColor color) : Piece(PieceType::Queen, color) {};

std::vector<sf::Vector2i> Queen::getValidMoves(sf::Vector2i currentSquare, const Board& board) const {
    std::vector<sf::Vector2i> validMoves = Rook::getSlidingMoves(currentSquare, board, color);
    std::vector<sf::Vector2i> diagonalMoves = Bishop::getDiagonalMoves(currentSquare, board, color);
    validMoves.insert(validMoves.end(), diagonalMoves.begin(), diagonalMoves.end());

    return validMoves;
}