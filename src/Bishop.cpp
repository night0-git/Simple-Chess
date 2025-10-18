#include "Bishop.h"
#include "board.h"

Bishop::Bishop(PieceColor color) : Piece(PieceType::Bishop, color) {};

std::vector<sf::Vector2i> Bishop::getValidMoves(sf::Vector2i currentSquare, const Board& board) const {
    return getDiagonalMoves(currentSquare, board, color);
}

std::vector<sf::Vector2i> Bishop::getDiagonalMoves(sf::Vector2i currentSquare, const Board& board, PieceColor color) {
    std::vector<sf::Vector2i> validMoves;
    validMoves.reserve(Board::SIZE * 2);
    // Bishop moves diagonally
    std::array<std::array<int, 2>, 4> dir = {{{1, 1}, {1, -1}, {-1, -1}, {-1, 1}}};
    for (int i = 0; i < 4; ++i) {
        int row = currentSquare.y + dir[i][0];
        int col = currentSquare.x + dir[i][1];
        while(board.isValidMove(color, {row, col})) {
            validMoves.push_back({row, col});
            row += dir[i][0];
            col += dir[i][1];
        }
    }
    return validMoves;
}