#include "../include/InputManager.h"
#include <iostream>
#include <utility>



InputManager::InputManager(std::map<sf::Event::EventType,
    std::vector<std::function<void(sf::Event)>>>& listnerMap)
        : listnerMap(listnerMap) {;
}

void InputManager::manage(const sf::Event event) {
    if (listnerMap.contains(event.type)) {
        for (std::function<void(sf::Event)> const& n : listnerMap.at(event.type)) {
            n(event);
        }
    }
}

/**
 *
 * @param event das Event für welches man sich anmelden will
 * @param function die Funktion die aufgerufen werden soll, wenn das Event passiert ist
 */
void InputManager::setListner(const sf::Event::EventType& event,
                              const std::function<void(sf::Event)>& function) {
    listnerMap[event].push_back(function);
}

