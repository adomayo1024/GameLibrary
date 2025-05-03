#include "Storage.h"

std::map<std::string, sf::Texture> Storage::textureSaves;

sf::Texture& Storage::getTexture(std::string& fileName) {
    if (!textureSaves.contains(fileName)) {
        textureSaves[fileName] = sf::Texture();
        textureSaves[fileName].loadFromFile(fileName);
    }
    return textureSaves[fileName];
}