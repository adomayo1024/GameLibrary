#pragma once


#include "Drawable.h"
#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>

#include "Updatable.h"


class Test : Drawable
             , Updatable{
public:
    void operator()(sf::Event);
    explicit Test(std::string, sf::Sprite&);
    sf::Drawable& draw() override;
    void update() override;
private:
    std::string text;
    sf::Sprite& sprite;
};
