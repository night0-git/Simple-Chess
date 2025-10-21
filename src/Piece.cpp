#include "Piece.h"

Piece::Piece(PieceType type_, PieceColor color_) : 
    type(type_),
    color(color_),
    hasMoved(false) // A new piece has not yet moved
{

}

PieceType Piece::getType() const {
    return type;
}

PieceColor Piece::getColor() const {
    return color;
}
