#include "Element.h"

#include <iostream>

int Element::anzahl = 0;
std::string Element::texturePath = "";
sf::Texture Element::texture;


Element::Element(std::string textPath) :  sprite(sf::Sprite{}){
    if (texturePath.empty()) {
        texturePath = textPath;
        texture.loadFromFile(texturePath);
    }
    sprite.setTexture(texture);
    sprite.setScale(10.f, 10.f);


}

sf::Sprite& Element::getSprite(){
    return sprite;
}

sf::Drawable& Element::draw() {
    return sprite;
}
