#pragma once
#include <functional>
#include <map>
#include <vector>
#include <SFML/Window/Event.hpp>



class InputManager {
public:
    explicit InputManager(std::map<sf::Event::EventType,
        std::vector<std::function<void(sf::Event)>>>&);
    void manage(sf::Event event);
    void setListner(const sf::Event::EventType& event,
        const std::function<void(sf::Event)>&);

private:
    std::map<sf::Event::EventType,
    std::vector<std::function<void(sf::Event)>>> listnerMap;
};
