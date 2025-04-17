#pragma once


#include "Drawable.h"
#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>


class Test : public Drawable {
public:
    void operator()(sf::Event);
    explicit Test(std::string, sf::Sprite&);
    sf::Drawable& draw() override;
private:
    std::string text;
    sf::Sprite& sprite;
};
