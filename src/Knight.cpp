#include "Knight.h"
#include "Board.h"

Knight::Knight(PieceColor color) : Piece(PieceType::Knight, color) {};

std::vector<sf::Vector2i> Knight::getValidMoves(sf::Vector2i currentSquare, const Board& board) const {
    std::vector<sf::Vector2i> validMoves;
    validMoves.reserve(8);  // Knight can move to 8 squares
    
    // The eight squares that a Knight could move to
    std::array<std::array<int, 2>, 8> moves = {{{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}}};
    for (int i = 0; i < 8; i++) {
        int row = currentSquare.y + moves[i][0];
        int col = currentSquare.x + moves[i][1];
        if (board.isValidMove(this->getColor(), {row, col})) {
            validMoves.push_back({row, col});
        }
    }
    return validMoves;
}