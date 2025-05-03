#pragma once
#include <functional>
#include <map>
#include <vector>
#include <SFML/Window/Event.hpp>



class InputManager {
public:
    explicit InputManager();
    void manage(sf::Event &);
    void setListner(
        const sf::Event::EventType&,
        const std::function<void(const sf::Event&)>&);
    void setListner(
        const sf::Event::EventType&,
        const sf::Keyboard::Key&,
        const std::function<void(const sf::Event&)>&);

private:
    std::map<sf::Event::EventType,
    std::vector<std::function<void(const sf::Event&)>>> listnerMap;
    std::map<sf::Event::EventType, std::map<sf::Keyboard::Key,
    std::vector<std::function<void(const sf::Event&)>>>> keyMap;
};
