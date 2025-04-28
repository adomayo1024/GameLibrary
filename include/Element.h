#pragma once
#include "Drawable.h"
#include "Updatable.h"
#include <SFML/Graphics/Sprite.hpp>


class Element: public Drawable,
               public Updatable{

public:
    explicit Element(sf::Sprite sprite);
    sf::Sprite& getSprite();
    sf::Drawable& draw() override;
    void update() override = 0;

protected:
    sf::Sprite sprite;

};

