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
    Piece* getPieceAt(sf::Vector2i square) const;
    // Return the captured piece, or nullptr if dest is empty
    std::unique_ptr<Piece> movePiece(sf::Vector2i src, sf::Vector2i dest);
    
    // Prevent capturing own piece or go out of bound
    bool isValidMove(PieceColor srcColor, sf::Vector2i dest) const;
private:
    void setupDefaultBoard();
    static bool isWithinBoard(sf::Vector2i square);
    // A grid of unique_ptr to Piece, an empty square holds nullptr
    std::array<std::array<std::unique_ptr<Piece>, SIZE>, SIZE> grid;
};