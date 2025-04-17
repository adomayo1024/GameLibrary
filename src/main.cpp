#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include <filesystem>

#include "DrawingManager.h"
#include "../include/InputManager.h"
#include "Test.h"

const unsigned int CELL_SIZE = 128;
const unsigned int ROWS = 10;
const unsigned int COLS = 10;
const unsigned int SCREEN_WIDTH = CELL_SIZE * ROWS;
const unsigned int SCREEN_HEIGHT =  CELL_SIZE * COLS;


int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Snake");
    window.setFramerateLimit(60);

    std::map<sf::Event::EventType,
    std::vector<std::function<void(sf::Event)>>> map{};
    InputManager input_manager(map);

    sf::Texture texture{};
    texture.loadFromFile("res/hässlichkeit.png");
    sf::Sprite sprite{};
    sprite.setTexture(texture);
    sprite.scale(8.0f, 8.0f);

    Test test("H", sprite);
    std::vector<std::shared_ptr<Drawable>> drawings{};
    std::shared_ptr<Test> test_ptr = std::make_shared<Test>(test);

    DrawingManager drawing_manager(window, drawings);
    drawing_manager.setDrawings(test_ptr);
    input_manager.setListner(sf::Event::KeyPressed, test);

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