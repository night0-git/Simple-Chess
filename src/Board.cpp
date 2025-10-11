#include "Board.h"
#include <iostream>

Board::Board() {
    setupDefaultBoard();
}

Piece Board::getPieceAt(int row, int col) const {
    if (row >= 0 && row <= BOARD_SIZE && col >= 0 && col <= BOARD_SIZE) {
        return grid[row][col];
    }
    return Piece();
}

void Board::setupDefaultBoard() {
    // Set up black pieces (on top)
    grid[0][0] = Piece(PieceType::Rook, PieceColor::Black);
    grid[0][1] = Piece(PieceType::Knight, PieceColor::Black);
    grid[0][2] = Piece(PieceType::Bishop, PieceColor::Black);
    grid[0][3] = Piece(PieceType::King, PieceColor::Black);
    grid[0][4] = Piece(PieceType::Queen, PieceColor::Black);
    grid[0][5] = Piece(PieceType::Bishop, PieceColor::Black);
    grid[0][6] = Piece(PieceType::Knight, PieceColor::Black);
    grid[0][7] = Piece(PieceType::Rook, PieceColor::Black);
    for (int col = 0; col < BOARD_SIZE; ++col) {
        grid[1][col] = Piece(PieceType::Pawn, PieceColor::Black);
    }

    // Set up white pieces (at bottom)
    grid[7][0] = Piece(PieceType::Rook, PieceColor::White);
    grid[7][1] = Piece(PieceType::Knight, PieceColor::White);
    grid[7][2] = Piece(PieceType::Bishop, PieceColor::White);
    grid[7][3] = Piece(PieceType::King, PieceColor::White);
    grid[7][4] = Piece(PieceType::Queen, PieceColor::White);
    grid[7][5] = Piece(PieceType::Bishop, PieceColor::White);
    grid[7][6] = Piece(PieceType::Knight, PieceColor::White);
    grid[7][7] = Piece(PieceType::Rook, PieceColor::White);
    for (int col = 0; col < BOARD_SIZE; ++col) {
        grid[6][col] = Piece(PieceType::Pawn, PieceColor::White);
    }
}

void Board::printBoard() const {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            Piece piece = getPieceAt(row, col);
            char pieceChar;
            switch (piece.getType()) {
                case PieceType::King:   pieceChar = 'K'; break;
                case PieceType::Queen:  pieceChar = 'Q'; break;
                case PieceType::Rook:   pieceChar = 'R'; break;
                case PieceType::Bishop: pieceChar = 'B'; break;
                case PieceType::Knight: pieceChar = 'N'; break;
                case PieceType::Pawn:   pieceChar = 'P'; break;
                case PieceType::Empty:  pieceChar = '.'; break;
            }

            if (piece.getColor() == PieceColor::Black) {
                pieceChar = tolower(pieceChar);
            }

            std::cout << pieceChar << " ";
        }
        std::cout << "\n";
    }
}

void Board::movePiece(sf::Vector2i src, sf::Vector2i dest) {
    if (!isWithinBoard(src.x, src.y) || !isWithinBoard(dest.x, dest.y)) {
        return;
    }
    grid[dest.x][dest.y] = grid[src.x][src.y];
    grid[src.x][dest.y] = Piece();
}
