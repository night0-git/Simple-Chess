#include "GameWindow.h"

GameWindow::GameWindow() :
    window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Simple Chess"),
    currentPlayerTurn(PieceColor::White),
    selectedSquare(std::nullopt)
{
    window.setFramerateLimit(60);
    loadResources();
}

void GameWindow::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void GameWindow::loadResources() {
    
}

// TODO: Fix git not applying renamed files