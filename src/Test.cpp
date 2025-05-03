#include "../include/Test.h"
#include <iostream>


Test::Test(const std::string textPath,
            sf::Event::EventType eventType)
    : Element(textPath), eventType(eventType) {
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


void Test::atInput(const sf::Event&) {
    std::cout << texturePath << std::endl;
}

void Test::moveRight(const sf::Event& event) {
    sprite.move(4.0, 0.0);
}

