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
    Game game{SCREEN_WIDTH, SCREEN_HEIGHT};

    std::map<sf::Event::EventType,
    std::vector<std::function<void(sf::Event)>>> map{};

    sf::Texture texture{};
    texture.loadFromFile("res/haesslichkeit.png");
    sf::Sprite sprite{};
    sprite.setTexture(texture);
    sprite.scale(8.0f, 8.0f);

    sf::Sprite sprite2{};
    sprite2.setTexture(texture);

    Test test{"Hello", sprite, sf::Event::KeyPressed};
    Test test2{"bye", sprite2, sf::Event::KeyPressed};
    Test test3(test);


    test3.atInput(sf::Event{});
    test3.setText("hi");
    test2.atInput(sf::Event{});

    InputManager input_manager{};
    input_manager.setListner(test.getEventType(), sf::Keyboard::Key::B, std::bind(&Test::atInput, &test, std::placeholders::_1));
    input_manager.setListner(test2.getEventType(), sf::Keyboard::Key::H, std::bind(&Test::atInput, &test2, std::placeholders::_1));



    while (game.isRunning()) {
        sf::Event event;
        while (game.getLastEvent(event)) {
            if (event.type == sf::Event::Closed) {
                game.endGame();
            }
            input_manager.manage(event);
        }

        game.draw();
    }
}