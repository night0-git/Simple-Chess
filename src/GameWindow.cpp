#include "GameWindow.h"
#include <iostream>


GameWindow::GameWindow() :
    window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Simple Chess"),
    board(),
    resourceManager(),
    currentTurn(PieceColor::White),
    selectedSquare(std::nullopt)
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

        if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
                sf::Vector2i clickedSquare = {
                    int(mouseButtonPressed->position.y / TILE_SIZE),
                    int(mouseButtonPressed->position.x / TILE_SIZE)
                };

                Piece* clickedPiece = board.getPieceAt(clickedSquare);
                

                if (selectedSquare) {
                    Piece* selectedPiece = board.getPieceAt(*selectedSquare);    // Always has value
                    // Safety check
                    if (!selectedPiece) {
                        selectedSquare = std::nullopt;
                        return;
                    }
                    if (clickedSquare == *selectedSquare) {
                        selectedSquare = std::nullopt;
                    }
                    else if (clickedPiece && clickedPiece->getColor() == currentTurn) {
                        selectedSquare = clickedSquare;
                    }
                    else {
                        auto validMoves = selectedPiece->getValidMoves(*selectedSquare, board);
                        for (const sf::Vector2i& move : validMoves) {
                            if (clickedSquare == move) {
                                std::unique_ptr<Piece> captured = nullptr;
                                if (board.getEnPassantTarget() && clickedSquare == *board.getEnPassantTarget()) {
                                    board.movePiece(*selectedSquare, clickedSquare);
                                    int forward = (selectedPiece->getColor() == PieceColor::White ? -1 : 1);
                                    captured = board.takePieceAt({clickedSquare.x - forward, clickedSquare.y});
                                }
                                else {
                                    captured = board.movePiece(*selectedSquare, clickedSquare);
                                }
                                if (captured) {
                                    discardedPieces.push_back(std::move(captured));
                                }
                                currentTurn = (currentTurn == PieceColor::White ? PieceColor::Black : PieceColor::White);
                                selectedSquare = std::nullopt;
                                break;
                            }
                        }
                    }
                }
                else {
                    if (clickedPiece && clickedPiece->getColor() == currentTurn) {
                        selectedSquare = clickedSquare;
                    }
                }
            }
        }
    }
}

void GameWindow::update() {

}

void GameWindow::render() {
    window.clear();

    resourceManager.draw(window, board, TILE_SIZE);

    window.display();
}


