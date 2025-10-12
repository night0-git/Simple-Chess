#include "Utils.h"


bool isWithinBoard(sf::Vector2i pos) {
    return (pos.x >= 0 && pos.x < Board::SIZE && pos.y >= 0 && pos.y < Board::SIZE);
}