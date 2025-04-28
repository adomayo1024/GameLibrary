#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <filesystem>

#include "DrawingManager.h"
#include "Game.h"
#include "InputManager.h"
#include "Test.h"
#include "UpdateManager.h"

constexpr  unsigned int CELL_SIZE = 128;
constexpr unsigned int ROWS = 10;
constexpr unsigned int COLS = 10;
constexpr unsigned int SCREEN_WIDTH = CELL_SIZE * ROWS;
constexpr unsigned int SCREEN_HEIGHT =  CELL_SIZE * COLS;


int main() {
    // Game game{SCREEN_WIDTH, SCREEN_HEIGHT};
    // game.init();
    //
    //
    //
    // while (game.isRunning()) {
    //     sf::Event event;
    //     while (game.getLastEvent(event)) {
    //         if (event.type == sf::Event::Closed) {
    //             game.endGame();
    //         }
    //         game.handleInput(event);
    //     }
    //
    //     game.draw();
    // }

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Moon");
    sf::Texture texture{};
    texture.loadFromFile("res/haesslichkeit.png");
    sf::Sprite sprite{};
    sprite.setTexture(texture);
    sprite.scale(8.0f, 8.0f);
    sprite.setPosition(sf::Vector2{212.0f, 0.0f});

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }

}