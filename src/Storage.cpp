#include "Storage.h"

#include <iostream>

std::map<std::string, sf::Texture> Storage::textureSaves;
std::map<Key, sf::Clock> Storage::keyClocks;

sf::Texture& Storage::getTexture(std::string path) {
    if (!textureSaves.contains(path)) {
        textureSaves[path] = sf::Texture();
        textureSaves[path].loadFromFile(path);
    }
    return textureSaves[path];
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
