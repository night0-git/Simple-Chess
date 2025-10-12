#pragma once

#include "Piece.h"
#include "Utils.h"
#include <SFML/Graphics.hpp>

class Board {
public:
    static constexpr int SIZE = 8;

    Board();
    // ~Board();

    // Get a non-owning pointer to the piece at the targeted square, nullptr if empty
    Piece* getPieceAt(sf::Vector2i pos) const;
    // Return the captured piece, or nullptr if dest is empty
    std::unique_ptr<Piece> movePiece(sf::Vector2i src, sf::Vector2i dest);
    
    bool isValidSquare(PieceColor srcColor, sf::Vector2i dest) const;
    static bool isWithinBoard(sf::Vector2i pos);

private:
    void setupDefaultBoard();
    // A grid of unique_ptr to Piece, an empty square holds nullptr
    std::array<std::array<std::unique_ptr<Piece>, SIZE>, SIZE> grid;
};