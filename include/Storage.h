#pragma once
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "TypBenenungen.h"

class Storage {

public:
    Storage() = default;
    static sf::Texture& getTexture(std::string);
    static const std::map<Key, sf::Clock> getPressedKeys();
    static void addKey(const Key);
    static bool containsKey(const Key);
    static bool areAnyKeysPressed();
    static sf::Clock& getClock(const Key);
    static void removeKey(const Key);

private:
    static std::map<std::string, sf::Texture> textureSaves;
    static std::map<Key, sf::Clock> keyClocks;
};
