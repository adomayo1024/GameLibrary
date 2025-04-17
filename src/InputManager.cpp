#include "../include/InputManager.h"
#include <iostream>
#include <utility>



InputManager::InputManager(std::map<sf::Event::EventType,
    std::vector<std::function<void(sf::Event)>>>& listnerMap)
: listnerMap(std::map<sf::Event::EventType,
std::vector<std::function<void(sf::Event)>>>{}) {;
}

void InputManager::manage(const sf::Event event) {
    if (listnerMap.contains(event.type)) {
        for (const std::function<void(sf::Event)> & listner : listnerMap.at(event.type)) {
            listner(event);
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

