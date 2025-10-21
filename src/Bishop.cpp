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
    std::array<sf::Vector2i, 4> dirs = {{
        {1, 1}, {1, -1}, {-1, -1}, {-1, 1}
    }};
    for (const auto& dir : dirs) {
        sf::Vector2i curr = currentSquare;
        bool hasCapturedPiece = false;
        while(board.isValidMove(color, curr + dir) && !hasCapturedPiece) {
            validMoves.push_back(curr + dir);
            if (board.getPieceAt(curr + dir)) {
                hasCapturedPiece = true;
            }
            curr += dir;
        }
    }
    return validMoves;
}