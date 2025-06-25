#include <SFML/Graphics.hpp>
#include "../include/Game.h"

constexpr unsigned int CELL_SIZE = 128;
constexpr unsigned int ROWS = 10;
constexpr unsigned int COLS = 10;
constexpr unsigned int SCREEN_WIDTH = CELL_SIZE * ROWS;
constexpr unsigned int SCREEN_HEIGHT =  CELL_SIZE * COLS;

int main() {

    myGE::Game game{SCREEN_WIDTH, SCREEN_HEIGHT};
    game.init();

    while (game.isRunning()) {
        myGE::Input input;
        while (game.getLastEvent(input)) {
            if (input.type == sf::Event::Closed) {
                game.endGame();
            }
            game.handleInput(input);
        }
        game.handleStillPressedKeys();
        game.update();
        game.draw();
        game.newFrame();
    }

}