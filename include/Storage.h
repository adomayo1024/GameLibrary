#pragma once
#include <map>
#include <SFML/Graphics/Texture.hpp>

class Storage {

public:
    Storage() = default;
    static sf::Texture& getTexture(std::string&);

private:
    static std::map<std::string, sf::Texture> textureSaves;
};
