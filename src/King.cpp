#include "King.h"
#include "Board.h"

King::King(PieceColor color) : Piece(PieceType::King, color) {};

std::vector<sf::Vector2i> King::getValidMoves(sf::Vector2i currentSquare, const Board& board) const {
    std::vector<sf::Vector2i> validMoves;
    validMoves.reserve(8);   // King can move to 8 squares

    // Surrounding squares
    std::array<std::array<int, 2>, 8> moves = {{{1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}}};
    for (int i = 0; i < 8; ++i) {
        int row = currentSquare.y + moves[i][0];
        int col = currentSquare.x + moves[i][1];
        if (board.isValidMove(this->getColor(), {row, col})) {
            validMoves.push_back({row, col});
        }
    }
    return validMoves;
}