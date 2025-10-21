#include "Knight.h"
#include "Board.h"

Knight::Knight(PieceColor color) : Piece(PieceType::Knight, color) {};

std::vector<sf::Vector2i> Knight::getValidMoves(sf::Vector2i currentSquare, const Board& board) const {
    std::vector<sf::Vector2i> validMoves;
    validMoves.reserve(8);  // Knight can move to 8 squares
    
    // The eight squares that a Knight could move to
    std::array<sf::Vector2i, 8> moves = {{
        {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
    }};
    for (const auto& move : moves) {
        if (board.isValidMove(color, currentSquare + move)) {
            validMoves.push_back(currentSquare + move);
        }
    }
    return validMoves;
}