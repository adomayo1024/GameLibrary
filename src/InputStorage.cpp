#include "InputStorage.h"

#include <array>
#include <iostream>

#include "MyTime.h"


namespace myGE {
    std::vector<Input> InputStorage::pressedInputs{};
    std::array<std::tuple<float, Input>, amountOnSavedInputs> InputStorage::lastInputs{};
    int InputStorage::i = 0;
}

void myGE::InputStorage::registerInput(Input &input) {
    float time = MyTime::getWholeTimeThisSession();
    std::tuple inputTuple{time, input};
    lastInputs[i] = inputTuple;
    i = (i + 1) % (amountOnSavedInputs + 1);

    if (Input::isItPressedInput(input)) {
        registerPressedInput(input);
    } else if (Input::isItReleasedInput(input)) {
        unregisterPressedInput(input);
    }
}

std::vector<myGE::Input> myGE::InputStorage::getPressedInputs() {
    return pressedInputs;
}

bool myGE::InputStorage::isPressedInputPressed(Input &input) {
    bool result = false;
    auto it = std::find(pressedInputs.begin(), pressedInputs.end(), input);
    if (it != pressedInputs.end()) {
        result = true;
    }
    return result;
}

bool myGE::InputStorage::areAnyPressedInputPressed() {
    return !pressedInputs.empty();
}

void myGE::InputStorage::removedAllPressedInputs() {
    pressedInputs.clear();
}

void myGE::InputStorage::registerPressedInput(const Input &input) {
    pressedInputs.emplace_back(input);
}

void myGE::InputStorage::unregisterPressedInput(const Input &input) {
    Input newInput{input};
    if (newInput.type == sf::Event::EventType::KeyReleased) {
        newInput.type = sf::Event::EventType::KeyPressed;
    } else if (newInput.type == sf::Event::EventType::MouseButtonReleased) {
        newInput.type = sf::Event::EventType::MouseButtonPressed;
    } else {
        newInput.type = sf::Event::EventType::JoystickButtonPressed;
    }

    auto it = std::find(pressedInputs.begin(), pressedInputs.end(), newInput);
    if (it != pressedInputs.end()) {
        pressedInputs.erase(it);
    }
}
