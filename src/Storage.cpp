#include "Storage.h"

#include <iostream>
#include <ostream>

std::map<std::string, sf::Texture> Storage::textureSaves;
std::map<Key, sf::Clock> Storage::keyClocks;

sf::Texture& Storage::getTexture(std::string fileName) {
    if (!textureSaves.contains(fileName)) {
        textureSaves[fileName] = sf::Texture();
        textureSaves[fileName].loadFromFile(fileName);
    }
    return textureSaves[fileName];
}

void Storage::addKey(const Key key) {
    keyClocks[key] = sf::Clock();
}

void Storage::removeKey(const Key key) {
    keyClocks.erase(key);
}

sf::Clock& Storage::getClock(const Key key) {
    return keyClocks[key];
}

bool Storage::containsKey(const Key key) {
    return keyClocks.contains(key);
}

bool Storage::areAnyKeysPressed(){
    return !keyClocks.empty();
}

const std::map<Key, sf::Clock> Storage::getPressedKeys() {
    return keyClocks;
}
