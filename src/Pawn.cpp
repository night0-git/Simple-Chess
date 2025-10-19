#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(PieceColor color) : Piece(PieceType::Pawn, color) {};

std::vector<sf::Vector2i> Pawn::getValidMoves(sf::Vector2i currentSquare, const Board& board) const {
    std::vector<sf::Vector2i> validMoves;
    validMoves.reserve(4);  // Pawn can move to 4 squares

    int forward = (color == PieceColor::Black ? 1 : -1);

    std::array<sf::Vector2i, 4> moves = {{
        currentSquare + sf::Vector2i(forward, 0), 
        currentSquare + sf::Vector2i(2 * forward, 0), 
        currentSquare + sf::Vector2i(forward, 1), 
        currentSquare + sf::Vector2i(forward, -1)
    }};

    if (board.isValidMove(color, moves[0]) && !board.getPieceAt(moves[0])) {
        validMoves.push_back(moves[0]);
        if (board.isValidMove(color, moves[1]) && !hasMoved && !board.getPieceAt(moves[1])) {
            validMoves.push_back(moves[1]);
        }
    }

    if (board.isValidMove(color, moves[2])) {
        if (board.getPieceAt(moves[2])) {
            validMoves.push_back(moves[2]);
        }
        // En passant
        else {
            if (board.getEnPassantTarget() && moves[2] == *board.getEnPassantTarget()) {
                validMoves.push_back(moves[2]);
            }
        }
    }

    if (board.isValidMove(color, moves[3])) {
        if (board.getPieceAt(moves[3])) {
            validMoves.push_back(moves[3]);
        }
        // En passant
        else {
            if (board.getEnPassantTarget() && moves[3] == *board.getEnPassantTarget()) {
                validMoves.push_back(moves[3]);
            }
        }
    }

    // TODO: promotion


    return validMoves;
}