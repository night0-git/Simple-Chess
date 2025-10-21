#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <optional>
#include "Board.h"
#include "ResourceManager.h"

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
    std::vector<std::unique_ptr<Piece>> discardedPieces;

    std::optional<sf::Vector2i> selectedSquare;
    PieceColor currentTurn;
    // TODO: checkmate
};