#pragma once

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(PieceColor color);

    virtual std::vector<sf::Vector2i> getValidMoves(sf::Vector2i currentPos, const Board& board) const override;

    static std::vector<sf::Vector2i> getDiagonalMoves(sf::Vector2i currentPos, const Board& board, PieceColor color);
};