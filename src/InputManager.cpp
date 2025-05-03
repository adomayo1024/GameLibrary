#include "../include/InputManager.h"
#include <iostream>
#include <utility>



InputManager::InputManager()
: listnerMap(std::map<sf::Event::EventType,
std::vector<std::function<void(const sf::Event&)>>>{}),
keyMap(std::map<sf::Event::EventType, std::map<sf::Keyboard::Key,
    std::vector<std::function<void(const sf::Event&)>>>>{}){
}

void InputManager::manage(sf::Event &event) {
    if (listnerMap.contains(event.type)) {
        for (const auto& listner : listnerMap[event.type]) {
            listner(event);
        }
    }
    else if (keyMap.contains(event.type)) {
        for (const auto& listener : keyMap[event.type][event.key.code]) {
            listener(event);
        }
    }
}

void InputManager::setListner(
    const sf::Event::EventType& event,
    const sf::Keyboard::Key &key,
    const std::function<void(const sf::Event &)> &function) {
    keyMap[event][key].push_back(function);
}


/**
 *
 * @param event das Event für welches man sich anmelden will
 * @param function die Funktion die aufgerufen werden soll, wenn das Event passiert ist
 */
void InputManager::setListner(const sf::Event::EventType& event,
                              const std::function<void(const sf::Event&)>& function) {
    listnerMap[event].push_back(function);
}

