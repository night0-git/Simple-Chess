#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(PieceColor color) : Piece(PieceType::Pawn, color) {};

std::vector<sf::Vector2i> Pawn::getValidMoves(sf::Vector2i currentSquare, const Board& board) const {
    std::vector<sf::Vector2i> validMoves;
    validMoves.reserve(4);  // Pawn can move to 4 squares

    PieceColor color = this->getColor();

    int forward = (color == PieceColor::Black ? 1 : -1);


    // Check first front square
    sf::Vector2i firstFrontMove = {currentSquare.y + forward, currentSquare.x};
    if (board.isValidMove(color, firstFrontMove)) {
        validMoves.push_back({firstFrontMove});
        // Second front square
        sf::Vector2i secondFrontMove = {currentSquare.y + (2 * forward), currentSquare.x};
        if (board.isValidMove(color, secondFrontMove)) {
            validMoves.push_back(secondFrontMove);
        }
    }
    // Check diagonal squares
    sf::Vector2i firstDiagonalSquare = {currentSquare.y + forward, currentSquare.x - 1};
    if (board.isValidMove(color, firstDiagonalSquare)) {
        validMoves.push_back(firstDiagonalSquare);
    }
    sf::Vector2i secondDiagonalSquare = {currentSquare.y + forward, currentSquare.x + 1};
    if (board.isValidMove(color, secondDiagonalSquare)) {
        validMoves.push_back(secondDiagonalSquare);
    }

    return validMoves;
}