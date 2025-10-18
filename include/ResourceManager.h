#pragma once

#include "Board.h"
#include <map>
#include <utility>

class ResourceManager {
public:
    ResourceManager();

    void testDraw(sf::RenderWindow& window);

    void draw(sf::RenderWindow& window, const Board& board, int TILE_SIZE);

private:
    sf::Sprite pieceSprite;
    sf::Sprite boardSprite;

    static const std::string pathToBoardAtlas;
    static const std::string pathToPieceAtlas;
    sf::Texture pieceAtlas;
    sf::Texture boardAtlas;

    std::map<std::pair<PieceType, PieceColor>, sf::IntRect> pieceRects;
    sf::IntRect lightSqrRect;
    sf::IntRect darkSqrRect;
    void setTextureRects();
    void getAssets();

    const int SQUARE_SIZE = 256;
    const int PAWN_WIDTH = 209;
    const int QUEEN_WIDTH = 281;
    const int KING_WIDTH = 254;
    const int BISHOP_WIDTH = 254;
    const int KNIGHT_WIDTH = 229;
    const int ROOK_WIDTH = 232;
};