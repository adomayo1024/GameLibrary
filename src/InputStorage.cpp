#include "InputStorage.h"

#include <array>
#include <iostream>

#include "MyTime.h"


namespace myGE {
    std::vector<Input> InputStorage::pressedInputs{};
    std::array<std::tuple<float, myGE::Input>, amountOnSavedInputs> InputStorage::lastInputs{};
    CycleInt InputStorage::i{amountOnSavedInputs};
    int InputStorage::howManyRegisterInputs = 0;
}

void myGE::InputStorage::registerInput(Input &input) {
    float time = MyTime::getWholeTimeThisSession();
    registeredInputs regInput{time, input};
    lastInputs[i++] = regInput;
    howManyRegisterInputs++;

    if(Input::isItPressedInput(input)) {
        registerPressedInput(input);
    } else if(Input::isItReleasedInput(input)) {
        unregisterPressedInput(input);
    }
}


const std::tuple<float, myGE::Input> &myGE::InputStorage::getLastInput() {
    if(howManyRegisterInputs <= 0) {
        throw std::runtime_error("No Input registered yet");
    }
    return lastInputs[i - 1];
}

std::vector<std::tuple<float, myGE::Input>> myGE::InputStorage::getLastNInputs(int n) {
    if(n <= 0) {
        throw std::runtime_error("Asked least for 1 Input");
    }
    if(n > amountOnSavedInputs) {
        throw std::runtime_error("Too many Inputs asked");
    }
    if(n > howManyRegisterInputs) {
        throw std::runtime_error("Not so many Inputs registered");
    }
    std::vector<registeredInputs> result{};

    for(int j = 1; j <= n; j++) {
        result.emplace_back(std::move(lastInputs[i - j]));
    }
    return result;
}

const std::vector<myGE::Input> &myGE::InputStorage::getPressedInputs() {
    return pressedInputs;
}

bool myGE::InputStorage::isPressedInputPressed(Input &input) {
    bool result = false;
    auto it = std::find(pressedInputs.begin(), pressedInputs.end(), input);
    if(it != pressedInputs.end()) {
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
    if(newInput.type == sf::Event::EventType::KeyReleased) {
        newInput.type = sf::Event::EventType::KeyPressed;
    } else if(newInput.type == sf::Event::EventType::MouseButtonReleased) {
        newInput.type = sf::Event::EventType::MouseButtonPressed;
    } else {
        newInput.type = sf::Event::EventType::JoystickButtonPressed;
    }

    auto it = std::find(pressedInputs.begin(), pressedInputs.end(), newInput);
    if(it != pressedInputs.end()) {
        pressedInputs.erase(it);
    }
}
