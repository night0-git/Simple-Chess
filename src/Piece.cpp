#include "Piece.h"

Piece::Piece(PieceType type_, PieceColor color_) : type(type_), color(color_) {}

PieceType Piece::getType() const {
    return type;
}

PieceColor Piece::getColor() const {
    return color;
}


