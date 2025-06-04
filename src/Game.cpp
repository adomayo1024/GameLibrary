#include "../include/Game.h"
#include "Storage.h"
#include "Test.h"
#include "TypBenenungen.h"
#include "Time.h"


myGE::Game::Game(int width, int heigth, const std::string& title)  :
window(sf::RenderWindow{sf::VideoMode(width, heigth), title}),
drawing_manager(DrawingManager{window}),
update_manager(UpdateManager{}),
input_manager(InputManager{}),
time(Time{0}) {
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(120);
    time.setWholeTime(0);   // TODO die Zeit muss aus einer Datei gelesen werden

}

sf::RenderWindow&myGE::Game::getWindow()  {
    return window;
}

void myGE::Game::endGame() {
    running = false;
    window.close();
}

bool myGE::Game::isRunning() const {
    return running;
}

bool myGE::Game::getLastEvent(sf::Event& event) {
    return window.pollEvent(event);
}

void myGE::Game::draw() {
    window.clear();
    drawing_manager.draw();
    window.display();
}

void myGE::Game::update() {
    update_manager.update();
}

void myGE::Game::handleInput(sf::Event& event) {
    input_manager.manage(event, time.getDeltaTime());
}

void myGE::Game::handleStillPressedKeys() {
    if (Storage::areAnyKeysPressed()) {
        input_manager.handleStillPressedKeys(time.getDeltaTime());
    }
}

myGE::GameState myGE::Game::getCurrentState() const {
    return currentState;
}

void myGE::Game::save() {

}

void myGE::Game::newFrame() {
    time.newFrame();
}


void myGE::Game::init() {
    makeGameObject("res/haesslichkeit.png");
    makeGameObject("res/gruen.png");
}

void myGE::Game::makeGameObject(std::string pathName) {
    std::shared_ptr<Test> test = std::make_shared<Test>(Test{pathName, sf::Event::KeyPressed});
    std::shared_ptr<myGE::Element> prt = test;
    std::shared_ptr<myGE::Drawable> prt_drawable = prt;
    std::shared_ptr<myGE::Updatable> prt_updatable = prt;
    gameElements.push_back(prt);
    update_manager.setUpdateObj(prt_updatable);
    drawing_manager.setDrawings(prt_drawable);
    std::vector<std::tuple<EventType,Key,inputHandlerFunktion>> liste = test->giveEventListner();
    input_manager.setListners(liste);
}
