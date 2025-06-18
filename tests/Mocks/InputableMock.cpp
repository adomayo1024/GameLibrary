#include "InputableMock.h"


std::vector<std::tuple<EventType, Key, inputHandlerFunktion>>
    InputableMock::giveEventListner(){
    std::vector<std::tuple<
    sf::Event::EventType,
    sf::Keyboard::Key,
    inputHandlerFunktion>> liste;

    liste.emplace_back(
    sf::Event::EventType::KeyPressed,
    sf::Keyboard::Key::Right,
    [this](const sf::Event& event, float deltaTime) {this->mockKey(event, deltaTime);});

    liste.emplace_back(
    sf::Event::EventType::MouseButtonPressed,
    sf::Keyboard::Key::Unknown,
    [this](const sf::Event& event, float deltaTime) {this->mockNotKey(event, deltaTime);});

    return liste;
}
