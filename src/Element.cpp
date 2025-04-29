#include "Element.h"

#include <iostream>

sf::Texture Element::texture;
std::string Element::texturePath;

Element::Element(std::string textPath) :  sprite(sf::Sprite()){
    if (texturePath.empty()) {
        texturePath = textPath;
        texture.loadFromFile(texturePath);
    }
    sprite.setTexture(texture);
}

sf::Sprite& Element::getSprite(){
    return sprite;
}

sf::Drawable& Element::draw() {
    return sprite;
}
