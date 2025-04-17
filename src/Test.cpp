//
// Created by ado_mayo1024 on 15.04.25.
//

#include "../include/Test.h"
#include <iostream>
#include <utility>


void Test::operator()(sf::Event event) {
    bool gg = (7 == event.key.code);
    std::cout << gg << std::endl;
}

Test::Test(std::string text, sf::Sprite& sprite)
    : text(text), sprite(sprite) {
}

sf::Drawable& Test::draw() {
    return sprite;
}

