//
// Created by ado_mayo1024 on 15.04.25.
//

#include "../include/Test.h"
#include <iostream>

Test::Test(const std::string text,
            sf::Sprite& sprite,
            sf::Event::EventType eventType)
    : text(text), sprite(sprite), eventType(eventType) {
}

Test::Test(const Test& test): text(test.text), sprite(test.sprite), eventType(test.eventType) {
}

Test::~Test() {
    std::cout << text << std::endl;
}


void Test::setEventType(sf::Event::EventType newEventType) {
    eventType = newEventType;
}

void Test::setText(std::string newText) {
    text = newText;
}

sf::Sprite& Test::getSprite() const {
    return sprite;
}



void Test::update() {
    sprite.setPosition(sprite.getPosition().x + 0.1f, sprite.getPosition().y + 0.1f);
}


sf::Drawable& Test::draw() {
    return sprite;
}

 sf::Event::EventType Test::getEventType() const {
    return eventType;
}

void Test::atInput(const sf::Event&) {
    std::cout << text << std::endl;
}
