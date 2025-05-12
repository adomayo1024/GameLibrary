#pragma once
#include <functional>
#include <map>
#include <vector>
#include <SFML/Window/Event.hpp>
#include "TypBenenungen.h"



class InputManager {
public:
    explicit InputManager();
    void manage(sf::Event &);
    void setListner(std::tuple<
        EventType,
        Key,
        inputHandlerFunktion>);
    void setListners(std::vector<
    std::tuple<
    EventType,
    Key,
    inputHandlerFunktion>>&);
    void handleStillPressedKeys();

private:
    std::map<sf::Event::EventType,
    std::vector<inputHandlerFunktion>> listnerMap;
    std::map<sf::Event::EventType, std::map<sf::Keyboard::Key,
    std::vector<inputHandlerFunktion>>> keyMap;
};
