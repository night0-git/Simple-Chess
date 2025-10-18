#pragma once

#include <SFML/Graphics.hpp>
#include <memory>   // For unique_ptr
#include <array>
#include <vector>


// Forward declaration to avoid circular dependency
class Board;

enum class PieceType {Pawn, Queen, King, Bishop, Knight, Rook, FIRST = Pawn, LAST = Rook};
enum class PieceColor {White, Black};

class Piece {
public: 
    Piece(PieceType type_, PieceColor color_);
    virtual ~Piece() = default;

    // Pure virtual function for getting valid moves, each piece must implement this
    virtual std::vector<sf::Vector2i> getValidMoves(sf::Vector2i currentSquare, const Board& board) const = 0;

    // Getters
    PieceType getType() const;
    PieceColor getColor() const;

protected:
    PieceType type;
    PieceColor color;

    bool hasMoved;
};

