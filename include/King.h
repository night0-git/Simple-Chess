#pragma once

#include "Piece.h"

class King : public Piece {
public:
    King(PieceColor color);

    virtual std::vector<sf::Vector2i> getValidMoves(sf::Vector2i currentSquare, const Board& board) const override;
};