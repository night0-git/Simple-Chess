#include "Rook.h"
#include "Board.h"

Rook::Rook(PieceColor color) : Piece(PieceType::Rook, color) {}

std::vector<sf::Vector2i> Rook::getValidMoves(sf::Vector2i currentSquare, const Board& board) const {
    return getSlidingMoves(currentSquare, board, this->getColor());
}

std::vector<sf::Vector2i> getSlidingMoves(sf::Vector2i currentSquare, const Board& board, PieceColor color) {
    std::vector<sf::Vector2i> validMoves;
    validMoves.reserve(board.SIZE * 2);
    
    // Rook moves vertically and horizontally
    std::array<std::array<int, 2>, 4> dir = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
    
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