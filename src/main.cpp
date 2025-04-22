#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <filesystem>

#include "DrawingManager.h"
#include "InputManager.h"
#include "Test.h"
#include "UpdateManager.h"

const unsigned int CELL_SIZE = 128;
const unsigned int ROWS = 10;
const unsigned int COLS = 10;
const unsigned int SCREEN_WIDTH = CELL_SIZE * ROWS;
const unsigned int SCREEN_HEIGHT =  CELL_SIZE * COLS;


int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Moon");
    window.setFramerateLimit(60);

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

    sf::Vector2<int> 

    test3.atInput(sf::Event{});
    test3.setText("hi");
    test2.atInput(sf::Event{});

    DrawingManager drawing_manager(window);

    InputManager input_manager{};
    input_manager.setListner(test.getEventType(),[&](sf::Event& event) {test.atInput(event);});
    input_manager.setListner(test2.getEventType(), [&](sf::Event& event) {test2.atInput(event);});

    UpdateManager update_manager{};


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            input_manager.manage(event);
        }

        window.clear();
        drawing_manager.draw();
        window.display();
    }
}