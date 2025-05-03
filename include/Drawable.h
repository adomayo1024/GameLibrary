#pragma once
#include <SFML/Graphics/Drawable.hpp>

class Drawable {
public:
    virtual sf::Drawable& draw() = 0;
    void switchActivity() {active %= 1;}
    bool isActive() const {return active;}
    Drawable() = default;
    virtual ~Drawable() = default;

    private:
    bool active = true;
};
