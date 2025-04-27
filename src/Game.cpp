#include "Game.h"

#include <SFML/Graphics/Texture.hpp>

#include "Test.h"


Game::Game(int width, int heigth, const std::string& title)  :
window(sf::RenderWindow{sf::VideoMode(width, heigth), title}),
drawing_manager(DrawingManager{window}),
update_manager(UpdateManager{}),
input_manager(InputManager{}){

}

sf::RenderWindow& Game::getWindow()  {
    return window;
}

void Game::endGame() {
    running = false;
    window.close();
}

bool Game::isRunning() const {
    return running;
}

bool Game::getLastEvent(sf::Event& event) {
    return window.pollEvent(event);
}

void Game::draw() {
    window.clear();
    drawing_manager.draw();
    window.display();
}

void Game::handleInput(sf::Event& event) {
    input_manager.manage(event);
}

GameState Game::getCurrentState() const {
    return currentState;
}

void Game::init() {
    sf::Texture texture{};
    texture.loadFromFile("res/haesslichkeit.png");
    sf::Sprite sprite{};
    sprite.setTexture(texture);
    sprite.scale(8.0f, 8.0f);

    sf::Sprite sprite2{};
    sprite2.setTexture(texture);

    Test test{"Hello", sprite, sf::Event::KeyPressed};

    input_manager.setListner(test.getEventType(), std::bind(&Test::atInput, &test, std::placeholders::_1));
}
