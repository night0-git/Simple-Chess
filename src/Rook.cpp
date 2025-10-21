#include "Rook.h"
#include "Board.h"

Rook::Rook(PieceColor color) : Piece(PieceType::Rook, color) {}

std::vector<sf::Vector2i> Rook::getValidMoves(sf::Vector2i currentSquare, const Board& board) const {
    return getSlidingMoves(currentSquare, board, color);
}

std::vector<sf::Vector2i> Rook::getSlidingMoves(sf::Vector2i currentSquare, const Board& board, PieceColor color) {
    std::vector<sf::Vector2i> validMoves;
    validMoves.reserve(Board::SIZE * 2);
    
    // Rook moves vertically and horizontally
    std::array<sf::Vector2i, 4> dirs = {{
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
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