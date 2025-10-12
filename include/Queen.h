#pragma once

#include "Piece.h"

class Queen : public Piece {
public:
    Queen(PieceColor color);

    virtual std::vector<sf::Vector2i> getValidMoves(sf::Vector2i currentPos, const Board& board) const override;
};