#include "../include/InputManager.h"
#include <tuple>
#include <utility>

#include "InputStorage.h"
#include "TypBenenungen.h"

myGE::InputManager::InputManager()
: listners(std::map<Input,
std::vector<inputHandlerFunktion>>{}){
}

myGE::InputManager::InputManager(std::vector<
    std::tuple<
    Input,
    inputHandlerFunktion>>& anmeldungsTupelListe):
listners(std::map<Input,
std::vector<inputHandlerFunktion>>{}){
    setListners(anmeldungsTupelListe);
}

void myGE::InputManager::manage(Input &input, float deltaTime) {
    if (listners.contains(input)) {
        for (const inputHandlerFunktion& listner : listners[input]) {
            listner(input, deltaTime);
        }
    }
    else if (Input::isItPressedInput(input) ||
        Input::isItReleasedInput(input)) {
        InputStorage::registerInput(input);
    }

}

void myGE::InputManager::handleStillPressedInput(float passTime) {
    for (auto& i : InputStorage::getPressedInputs()) {
        for (const auto& listner : pressedListners[i]) {
            listner(i, passTime);
        }
    }
}


void myGE::InputManager::setListner(std::tuple<
    Input,
    inputHandlerFunktion>& listner) {

    Input &input = std::get<0>(listner);
    inputHandlerFunktion funktion = std::get<1>(listner);

    if (Input::isItPressedInput(input)) {
        if (pressedListners.contains(input)) {
            pressedListners[input].emplace_back(funktion);
        }
        else {
            std::vector liste{funktion};
            pressedListners[std::get<0>(listner)] = liste;
        }
    }
    else {
        if (listners.contains(input)) {
            listners[input].emplace_back(funktion);
        }
        else {
            std::vector liste{funktion};
            listners[std::get<0>(listner)] = liste;
        }
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


