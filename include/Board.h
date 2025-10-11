#pragma once

#include "Piece.h"
#include "Utils.h"
#include <SFML/Graphics.hpp>
#include <array>

constexpr int BOARD_SIZE = 8;

class Board {
public:
    Board();
    void printBoard() const;
    Piece getPieceAt(int row, int col) const;
    void movePiece(sf::Vector2i src, sf::Vector2i dest);

private:
    void setupDefaultBoard();
    std::array<std::array<Piece, BOARD_SIZE>, BOARD_SIZE> grid;
};