#pragma once

#include "Piece.h"

class Knight : public Piece {
public:
    Knight(PieceColor color);

    virtual std::vector<sf::Vector2i> getValidMoves(sf::Vector2i currentSquare, const Board& board) const override;
};