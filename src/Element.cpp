#include "Element.h"


Element::Element(sf::Sprite sprite) : sprite(sprite){

}

sf::Sprite& Element::getSprite(){
    return sprite;
}

sf::Drawable& Element::draw() {
    return sprite;
}
