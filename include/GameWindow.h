#pragma once

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "ResourceManager.h"
#include <string>

class GameWindow {
public:
    const unsigned int TILE_SIZE = 150;
    const unsigned int WINDOW_WIDTH = TILE_SIZE * Board::SIZE;
    const unsigned int WINDOW_HEIGHT = TILE_SIZE * Board::SIZE;

    GameWindow();

    void run();

private:
    void handleEvents();
    void update();
    void render();


    sf::RenderWindow window;
    Board board;
    ResourceManager resourceManager;
};