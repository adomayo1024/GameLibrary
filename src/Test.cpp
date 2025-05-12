#include "../include/Test.h"
#include <iostream>
#include <tuple>
#include <vector>

Test::Test(const std::string textPath,
           sf::Event::EventType eventType)
    : Element(textPath), eventType(eventType), velocity(1) {
}


Test::~Test() {
    std::cout << "Test deleted" << std::endl;
}


void Test::setEventType(sf::Event::EventType newEventType) {
    eventType = newEventType;
}


void Test::update() {
    sprite.setPosition(sprite.getPosition().x + 0.1f, sprite.getPosition().y + 0.1f);
}

 sf::Event::EventType Test::getEventType() const {
    return eventType;
}

std::vector<std::tuple<sf::Event::EventType, sf::Keyboard::Key, std::function<void(const sf::Event &)>>>
Test::giveEventListner() {
    std::vector<std::tuple<
        sf::Event::EventType,
        sf::Keyboard::Key,
        std::function<void(const sf::Event&)>>> liste;

    liste.emplace_back(
        sf::Event::EventType::KeyPressed,
        sf::Keyboard::Key::Right,
        [this](const sf::Event& e) {this->moveRight(e);});

    liste.emplace_back(
        sf::Event::EventType::KeyPressed,
        sf::Keyboard::Key::Left,
        [this](const sf::Event& e) {this->moveLeft(e);});

    liste.emplace_back(
        sf::Event::EventType::KeyPressed,
        sf::Keyboard::Key::Up,
        [this](const sf::Event& e) {this->moveUp(e);});

    liste.emplace_back(
        sf::Event::EventType::KeyPressed,
        sf::Keyboard::Key::Down,
        [this](const sf::Event& e) {this->moveDown(e);});


    return liste;

}



void Test::atInput(const sf::Event&) {
    if (Inputable::isActive()) {
        std::cout << texturePath << std::endl;
    }
}

void Test::moveRight(const sf::Event& event) {
    if (Inputable::isActive()) {
        sprite.move(velocity, 0.0);
    }
}

void Test::moveLeft(const sf::Event &) {
    if (Inputable::isActive()) {
        sprite.move(velocity * -1, 0.0);
    }
}

void Test::moveUp(const sf::Event& event) {
    if (Inputable::isActive()) {
        sprite.move(0.0, velocity * -1);
    }
}

void Test::moveDown(const sf::Event& event) {
    if (Inputable::isActive()) {
        sprite.move(0.0, velocity);
    }
}