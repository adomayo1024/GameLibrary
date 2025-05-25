#include "../include/InputManager.h"
#include <tuple>
#include <utility>

#include "Storage.h"
#include "TypBenenungen.h"




InputManager::InputManager()
: listnerMap(std::map<sf::Event::EventType,
std::vector<inputHandlerFunktion>>{}),
keyMap(std::map<sf::Event::EventType, std::map<sf::Keyboard::Key,
    std::vector<inputHandlerFunktion>>>{}){
}

void InputManager::manage(sf::Event &event, float passTime) {

    if (listnerMap.contains(event.type)) {
        for (const auto& listner : listnerMap[event.type]) {
            listner(event, passTime);
        }
    }
    else if (keyMap.contains(event.type)) {
        Key key = event.key.code;
        if (!Storage::containsKey(key)) {
            Storage::addKey(key);
        }
    }
    else if (event.type == sf::Event::KeyReleased) {
        Storage::removeKey(event.key.code);
    }
}


void InputManager::handleStillPressedKeys(float passTime) {
    for (auto i : Storage::getPressedKeys()) {
        Key key = i.first;
        for (const auto& listner : keyMap[EventType::KeyPressed][key]) {
            sf::Event newEvent;
            newEvent.type = EventType::KeyPressed;
            newEvent.key.code = key;
            listner(newEvent, passTime);
        }
    }
}


void InputManager::setListner(std::tuple<
    EventType,
    Key,
    inputHandlerFunktion> tupel) {

    sf::Event::EventType type = std::get<0>(tupel);
    sf::Keyboard::Key key = std::get<1>(tupel);
    inputHandlerFunktion function = std::move(std::get<2>(tupel));

    if (std::get<1>(tupel)) {
        keyMap[type][key].push_back(function);
    }
    else {
        listnerMap[type].push_back(function);
    }
}

void InputManager::setListners(std::vector<
    std::tuple<
    EventType,
    Key,
    inputHandlerFunktion>>& listners) {
    for (auto& listner : listners) {
        setListner(listner);
    }
}


