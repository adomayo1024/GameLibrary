#include "Element.h"

#include <iostream>

#include "Storage.h"


myGE::Element::Element(std::string textPath) :  sprite(sf::Sprite()),
                                                texture(Storage::getTexture(textPath)),
                                                texturePath(textPath),
                                                deltaClock(sf::Clock{}){
    sprite.setTexture(texture);
}

sf::Sprite&myGE::Element::getSprite(){
    return sprite;
}

sf::Drawable&myGE::Element::draw() {
    return sprite;
}
