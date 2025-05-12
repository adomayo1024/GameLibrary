#include "../include/Game.h"

#include "Storage.h"
#include "Test.h"
#include "TypBenenungen.h"



Game::Game(int width, int heigth, const std::string& title)  :
window(sf::RenderWindow{sf::VideoMode(width, heigth), title}),
drawing_manager(DrawingManager{window}),
update_manager(UpdateManager{}),
input_manager(InputManager{}){
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(120);

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

void Game::handleStillPressedKeys() {
    if (Storage::areAnyKeysPressed()) {
        input_manager.handleStillPressedKeys();
    }
}

GameState Game::getCurrentState() const {
    return currentState;
}

void Game::init() {
    std::shared_ptr<Test> test = std::make_shared<Test>(Test{"res/haesslichkeit.png", sf::Event::KeyPressed});
    std::shared_ptr<Element> prt = test;
    std::shared_ptr<Drawable> prt_drawable = prt;
    gameElements.push_back(prt);
    drawing_manager.setDrawings(prt_drawable);
    std::vector<std::tuple<EventType,Key,inputHandlerFunktion>> liste = test->giveEventListner();
    input_manager.setListners(liste);
}
