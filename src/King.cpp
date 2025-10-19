#include "King.h"
#include "Board.h"

King::King(PieceColor color) : Piece(PieceType::King, color) {};

std::vector<sf::Vector2i> King::getValidMoves(sf::Vector2i currentSquare, const Board& board) const {
    std::vector<sf::Vector2i> validMoves;
    validMoves.reserve(8);   // King can move to 8 squares

    // Surrounding squares
    std::array<sf::Vector2i, 8> moves = {{
        {1,  1}, {1,  0}, {1, -1}, {0, -1}, {-1, -1}, {-1,  0}, {-1,  1}, {0,  1}
    }};
    for (const auto& move : moves) {
        if (board.isValidMove(color, currentSquare + move)) {
            validMoves.push_back(currentSquare + move);
        }
    }

    // TODO: castling, checked square

    return validMoves;
}