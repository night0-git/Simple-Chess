#pragma once

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(PieceColor color);

    virtual std::vector<sf::Vector2i> getValidMoves(sf::Vector2i currentSquare, const Board& board) const override;

    static std::vector<sf::Vector2i> getSlidingMoves(sf::Vector2i currentSquare, const Board& board, PieceColor color);
};