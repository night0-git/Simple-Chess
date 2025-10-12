#include "Queen.h"
#include "Board.h"
#include "Rook.h"
#include "Bishop.h"

Queen::Queen(PieceColor color) : Piece(PieceType::Queen, color) {};

std::vector<sf::Vector2i> Queen::getValidMoves(sf::Vector2i currentSquare, const Board& board) const {
    PieceColor color = this->getColor();
    // Get a Rook's moves
    std::vector<sf::Vector2i> validMoves = Rook::getSlidingMoves(currentSquare, board, color);
    // Get a Bishop's moves
    std::vector<sf::Vector2i> diagnonalMoves = Bishop::getDiagonalMoves(currentSquare, board, color);
    // Combine
    validMoves.insert(validMoves.end(), diagnonalMoves.begin(), diagnonalMoves.end());

    return validMoves;
}