#include "../include/InputManager.h"
#include <tuple>
#include <utility>

#include "Storage.h"
#include "TypBenenungen.h"




myGE::InputManager::InputManager()
: listners(std::map<Input,
std::vector<inputHandlerFunktion>>{}),
keyMap(std::map<sf::Event::EventType, std::map<sf::Keyboard::Key,
    std::vector<inputHandlerFunktion>>>{}){
}

myGE::InputManager::InputManager(std::vector<
    std::tuple<
    Input,
    inputHandlerFunktion>>& anmeldungsTupelListe):
listners(std::map<Input,
std::vector<inputHandlerFunktion>>{}),
keyMap(std::map<sf::Event::EventType, std::map<sf::Keyboard::Key,
    std::vector<inputHandlerFunktion>>>{}){
    setListners(anmeldungsTupelListe);
}

void myGE::InputManager::manage(Input &input, float deltaTime) {
    if (listners.contains(input)) {
        for (const inputHandlerFunktion& listner : listners[input]) {
            listner(input, deltaTime);
        }
    }
}


void myGE::InputManager::handleStillPressedKeys(float passTime) {
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


void myGE::InputManager::setListner(std::tuple<
    Input,
    inputHandlerFunktion> listner) {

    Input &input = std::get<0>(listner);
    inputHandlerFunktion funktion = std::get<1>(listner);

    if (listners.contains(input)) {
        listners[input].emplace_back(funktion);
    }
    else {
        std::vector liste{funktion};
        listners[std::get<0>(listner)] = liste;
    }
}

void myGE::InputManager::setListners(std::vector<
    std::tuple<
    Input,
    inputHandlerFunktion>>& listners) {
    for (auto& listner : listners) {
        setListner(listner);
    }
}


