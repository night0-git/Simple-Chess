#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Piece.h"
#include <optional>
#include <map>

const unsigned int TILE_SIZE = 80;
const unsigned int WINDOW_WIDTH = TILE_SIZE * Board::SIZE;
const unsigned int WINDOW_HEIGHT = TILE_SIZE * Board::SIZE;


class GameWindow {
public:
    GameWindow();
    void run();

private:
    // Game loop methods
    void processEvents();
    void update();
    void render();

    // Helper methods
    void loadResources();
    void drawBoard();
    void drawPieces();
    void handleMouseClick(const sf::Vector2f& mousePos);

    // Window object
    sf::RenderWindow window;

    Board board;

    // Game state
    PieceColor currentPlayerTurn;
    std::optional<sf::Vector2i> selectedSquare;

    // Resources
    sf::Texture pieceTexture;
    std::map<PieceColor, std::map<PieceType, sf::Sprite>> pieceSprites;
};