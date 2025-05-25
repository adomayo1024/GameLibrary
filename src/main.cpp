#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <filesystem>

#include "DrawingManager.h"
#include "../include/Game.h"
#include "InputManager.h"
#include "Test.h"
#include "UpdateManager.h"
#include "TypBenenungen.h"

constexpr unsigned int CELL_SIZE = 128;
constexpr unsigned int ROWS = 10;
constexpr unsigned int COLS = 10;
constexpr unsigned int SCREEN_WIDTH = CELL_SIZE * ROWS;
constexpr unsigned int SCREEN_HEIGHT =  CELL_SIZE * COLS;



int main() {

    Game game{SCREEN_WIDTH, SCREEN_HEIGHT};
    game.init();

    while (game.isRunning()) {
        sf::Event event{};
        while (game.getLastEvent(event)) {
            if (event.type == sf::Event::Closed) {
                game.endGame();
            }
            game.handleInput(event);
        }
        game.handleStillPressedKeys();
        game.update();
        game.draw();
        game.newFrame();
    }

}