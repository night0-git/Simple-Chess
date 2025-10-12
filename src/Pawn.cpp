#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(PieceColor color) : Piece(PieceType::Pawn, color) {};

std::vector<sf::Vector2i> Pawn::getValidMoves(sf::Vector2i currentPos, const Board& board) const {
    std::vector<sf::Vector2i> validMoves;
    validMoves.reserve(4);  // Pawn can move to 4 squares

    PieceColor color = this->getColor();

    int forward = (color == PieceColor::Black ? 1 : -1);


    // Check first front square
    sf::Vector2i firstFrontMove = {currentPos.y + forward, currentPos.x};
    if (board.isValidSquare(color, firstFrontMove)) {
        validMoves.push_back({firstFrontMove});
        // Second front square
        sf::Vector2i secondFrontMove = {currentPos.y + (2 * forward), currentPos.x};
        if (board.isValidSquare(color, secondFrontMove)) {
            validMoves.push_back(secondFrontMove);
        }
    }
    // Check diagonal squares
    sf::Vector2i firstDiagonalSquare = {currentPos.y + forward, currentPos.x - 1};
    if (board.isValidSquare(color, firstDiagonalSquare)) {
        validMoves.push_back(firstDiagonalSquare);
    }
    sf::Vector2i secondDiagonalSquare = {currentPos.y + forward, currentPos.x + 1};
    if (board.isValidSquare(color, secondDiagonalSquare)) {
        validMoves.push_back(secondDiagonalSquare);
    }

    return validMoves;
}