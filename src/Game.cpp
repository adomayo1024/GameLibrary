#include "../include/Game.h"
#include "Storage.h"
#include "Test.h"
#include "TypBenenungen.h"
#include "Time.h"



Game::Game(int width, int heigth, const std::string& title)  :
window(sf::RenderWindow{sf::VideoMode(width, heigth), title}),
drawing_manager(DrawingManager{window}),
update_manager(UpdateManager{}),
input_manager(InputManager{}),
time(Time{0}) {
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(120);
    time.setWholeTime(0);   // TODO die Zeit muss aus einer Datei gelesen werden

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

void Game::update() {
    update_manager.update();
}

void Game::handleInput(sf::Event& event) {
    input_manager.manage(event, time.getDeltaTime());
}

void Game::handleStillPressedKeys() {
    if (Storage::areAnyKeysPressed()) {
        input_manager.handleStillPressedKeys(time.getDeltaTime());
    }
}

GameState Game::getCurrentState() const {
    return currentState;
}

void Game::save() {

}

void Game::newFrame() {
    time.newFrame();
}


void Game::init() {
    makeGameObject("res/haesslichkeit.png");
    makeGameObject("res/gruen.png");
}

void Game::makeGameObject(std::string pathName) {
    std::shared_ptr<Test> test = std::make_shared<Test>(Test{pathName, sf::Event::KeyPressed});
    std::shared_ptr<Element> prt = test;
    std::shared_ptr<Drawable> prt_drawable = prt;
    std::shared_ptr<Updatable> prt_updatable = prt;
    gameElements.push_back(prt);
    update_manager.setUpdateObj(prt_updatable);
    drawing_manager.setDrawings(prt_drawable);
    std::vector<std::tuple<EventType,Key,inputHandlerFunktion>> liste = test->giveEventListner();
    input_manager.setListners(liste);
}
