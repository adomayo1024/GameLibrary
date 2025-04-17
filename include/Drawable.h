#pragma once
#include <SFML/Graphics/Drawable.hpp>

class Drawable {

public:
    virtual sf::Drawable& draw() = 0;
    Drawable() = default;
    virtual ~Drawable() = default;

};

