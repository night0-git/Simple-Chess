#pragma once

enum class PieceType {
    King,
    Queen,
    Rook,
    Bishop,
    Knight,
    Pawn,
    Empty
};

enum class PieceColor {
    White,
    Black,
    None
};

class Piece {
public: 
    Piece(PieceType type = PieceType::Empty, PieceColor color = PieceColor::None);

    PieceType getType() const;
    PieceColor getColor() const;

private:
    PieceType type;
    PieceColor color;
};

