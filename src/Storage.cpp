#include "Storage.h"

#include <iostream>

std::map<std::string, sf::Texture> myGE::Storage::textureSaves;
std::map<Key, sf::Clock> myGE::Storage::keyClocks;

sf::Texture&myGE::Storage::getTexture(std::string path) {
    if (!textureSaves.contains(path)) {
        textureSaves[path] = sf::Texture();
        textureSaves[path].loadFromFile(path);
    }
    return textureSaves[path];
}

void myGE::Storage::addKey(const Key key) {
    keyClocks[key] = sf::Clock();
}

void myGE::Storage::removeKey(const Key key) {
    keyClocks.erase(key);
}

void myGE::Storage::removeAllKeys() {
    keyClocks.clear();
}

sf::Clock& myGE::Storage::getClock(const Key key) {
    return keyClocks[key];
}

bool myGE::Storage::containsKey(const Key key) {
    return keyClocks.contains(key);
}

bool myGE::Storage::areAnyKeysPressed(){
    return !keyClocks.empty();
}

const std::map<Key, sf::Clock> myGE::Storage::getPressedKeys() {
    return keyClocks;
}
