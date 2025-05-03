#include "../include/Game.h"

#include <complex>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>

#include "Storage.h"
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
    drawing_manager.getDrawings().at(0)->draw();
    input_manager.manage(event);
}

GameState Game::getCurrentState() const {
    return currentState;
}

void Game::init() {

    std::shared_ptr<Element> prt = std::make_shared<Test>(Test{"res/haesslichkeit.png", sf::Event::KeyPressed});
    std::shared_ptr<Drawable> prt_drawable = prt;
    gameElements.push_back(prt);
    drawing_manager.setDrawings(prt_drawable);
    input_manager.setListner(sf::Event::KeyPressed, sf::Keyboard::Key::D, std::bind(&Test::moveRight, &prt, std::placeholders::_1));

}
