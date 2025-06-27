#include "../include/Test.h"
#include <iostream>
#include <tuple>
#include <vector>

#include "Storage.h"

Test::Test(const std::string textPath)
    : myGE::Element(textPath), velocity(100) {
}


Test::~Test() {
    std::cout << "Test deleted" << std::endl;
}

void Test::update() {
    //sprite.setPosition(sprite.getPosition().x + 0.1f, sprite.getPosition().y + 0.1f);
}


std::vector<std::tuple<myGE::Input, inputHandlerFunktion>>
Test::giveEventListner() {
    std::vector<std::tuple<
        myGE::Input,
        inputHandlerFunktion>> liste;
//TODO key werden zu unknown
    liste.emplace_back(
        myGE::Input{myGE::Input::ParameterInputKonstruktor{.type=sf::Event::EventType::KeyPressed, .key=sf::Keyboard::Key::Right}},
        [this](const sf::Event& e, float deltaTime) {this->moveRight(e, deltaTime);});

    liste.emplace_back(
    myGE::Input{myGE::Input::ParameterInputKonstruktor{.type=sf::Event::EventType::KeyPressed, .key=sf::Keyboard::Key::Left}},
        [this](const sf::Event& e, float deltaTime) {this->moveLeft(e, deltaTime);});

    liste.emplace_back(
    myGE::Input{myGE::Input::ParameterInputKonstruktor{.type=sf::Event::EventType::KeyPressed, .key=sf::Keyboard::Key::Up}},
        [this](const sf::Event& e, float deltaTime) {this->moveUp(e, deltaTime);});

    liste.emplace_back(
    myGE::Input{myGE::Input::ParameterInputKonstruktor{.type=sf::Event::EventType::KeyPressed, .key=sf::Keyboard::Key::Down}},
        [this](const sf::Event& e, float deltaTime) {this->moveDown(e, deltaTime);});


    return liste;

}
void Test::atInput(const sf::Event& event, float) {
    if (myGE::Inputable::isActive()) {
        std::cout << texturePath << std::endl;
    }
}

void Test::moveRight(const sf::Event& event, float deltaTime) {
    if (myGE::Inputable::isActive()) {
        sprite.move(velocity * deltaTime, 0.0);
    }
}

void Test::moveLeft(const sf::Event& event, float deltaTime) {
    if (myGE::Inputable::isActive()) {
        sprite.move(velocity * -1 * deltaTime, 0.0);
    }
}

void Test::moveUp(const sf::Event& event, float deltaTime) {
    if (myGE::Inputable::isActive()) {
        sprite.move(0.0, velocity * -1 * deltaTime);
    }
}

void Test::moveDown(const sf::Event& event, float deltaTime) {
    if (myGE::Inputable::isActive()) {
        sprite.move(0.0, velocity * deltaTime);
    }
}