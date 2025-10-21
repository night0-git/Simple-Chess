#pragma once

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(PieceColor color);

    virtual std::vector<sf::Vector2i> getValidMoves(sf::Vector2i currentSquare, const Board& board) const override;
};