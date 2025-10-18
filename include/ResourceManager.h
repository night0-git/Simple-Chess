#pragma once

#include "Board.h"
#include <map>
#include <utility>

class ResourceManager {
public:
    ResourceManager();

    void draw(sf::RenderWindow& window, const Board& board, int TILE_SIZE);

private:
    sf::Sprite pieceSprite;
    sf::Sprite boardSprite;

    const int SQUARE_SIZE = 256;
    static const std::string pathToBoardAtlas;
    static const std::string pathToPieceAtlas;
    sf::Texture pieceAtlas;
    sf::Texture boardAtlas;

    std::map<std::pair<PieceType, PieceColor>, sf::IntRect> pieceRects;
    sf::IntRect lightSqrRect;
    sf::IntRect darkSqrRect;
    void setTextureRects();
    void getAssets();
};