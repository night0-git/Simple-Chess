#include "Piece.h"

Piece::Piece(PieceType type_, PieceColor color_) : 
    type(type_),
    color(color_),
    hasMoved(false) // A new piece has not yet moved
{
    // TODO: construct sprite
}

PieceType Piece::getType() const {
    return type;
}

PieceColor Piece::getColor() const {
    return color;
}

void Piece::draw(sf::RenderTarget& target) const {
    target.draw(sprite);
}

void Piece::setScreenPosition(float x, float y) {
    sprite.setPosition({x, y});
}

void Piece::setTexture(const sf::Texture& texture, const sf::IntRect& textureRect) {
    sprite.setTexture(texture);
    sprite.setTextureRect(textureRect);
}

