#pragma once

#include <memory>   // For unique_ptr
#include <array>
#include <vector>
#include <SFML/Graphics.hpp>

// Forward declaration to avoid circular dependency
class Board;

enum class PieceType { King, Queen, Rook, Bishop, Knight, Pawn };

enum class PieceColor { White, Black };

class Piece {
public: 
    Piece(PieceType type, PieceColor color);

    virtual ~Piece() = default;

    // Pure virtual function for getting valid moves, each piece must implement this
    virtual std::vector<sf::Vector2i> getValidMoves(sf::Vector2i currentPos, const Board& board) const = 0;

    // Draw the piece sprite to given target
    void draw(sf::RenderTarget& target) const;

    // Sets the visual screen position of the sprite
    void setScreenPosition(float x, float y);
    // Sets the texture for the sprite (e.g., from a texture atlas)
    void setTexture(const sf::Texture& texture, const sf::IntRect& textureRect);

    // Getters
    PieceType getType() const;
    PieceColor getColor() const;

protected:
    PieceType type;
    PieceColor color;
    sf::Sprite sprite;

    bool hasMoved;
};

