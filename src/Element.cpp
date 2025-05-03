#include "Element.h"

#include <iostream>

#include "Storage.h"


Element::Element(std::string textPath) :  sprite(sf::Sprite()), texture(Storage::getTexture(textPath)) {
    sprite.setTexture(texture);
}

sf::Sprite& Element::getSprite(){
    return sprite;
}

sf::Drawable& Element::draw() {
    return sprite;
}
