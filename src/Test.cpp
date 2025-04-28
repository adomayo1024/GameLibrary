//
// Created by ado_mayo1024 on 15.04.25.
//

#include "../include/Test.h"
#include <iostream>

Test::Test(const std::string text,
            sf::Sprite sprite,
            sf::Event::EventType eventType)
    : Element(sprite), text(text), eventType(eventType) {
}


Test::~Test() {
}


void Test::setEventType(sf::Event::EventType newEventType) {
    eventType = newEventType;
}

void Test::setText(std::string newText) {
    text = newText;
}

void Test::update() {
    sprite.setPosition(sprite.getPosition().x + 0.1f, sprite.getPosition().y + 0.1f);
}

 sf::Event::EventType Test::getEventType() const {
    return eventType;
}

void Test::atInput(const sf::Event&) {
    std::cout << text << std::endl;
}
