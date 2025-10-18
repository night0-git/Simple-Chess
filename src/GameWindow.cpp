#include "GameWindow.h"
#include <iostream>


GameWindow::GameWindow() :
    window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Simple Chess"),
    board(),
    resourceManager()
{};

void GameWindow::run() {
    while (window.isOpen()) {
        handleEvents();



        update();
        render();
    }
}

void GameWindow::handleEvents() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }

    }
}

void GameWindow::update() {

}

void GameWindow::render() {
    window.clear();

    resourceManager.draw(window, board, TILE_SIZE);
    // resourceManager.testDraw(window);

    window.display();
}


