#pragma once
#include "Drawable.h"
#include "Updatable.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


class Element: public Drawable,
               public Updatable{

public:
    explicit Element(std::string);
    sf::Sprite& getSprite();
    sf::Drawable& draw() override;
    void update() override = 0;

protected:
    sf::Sprite sprite;
    static sf::Texture texture;
    static std::string texturePath;
    static int anzahl;

};

