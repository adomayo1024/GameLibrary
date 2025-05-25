#pragma once

#include <string>
#include <vector>
#include <SFML/Window/Event.hpp>
#include "Element.h"
#include "Inputable.h"


class Test : public Element, public Inputable{
public:
    explicit Test(std::string, sf::Event::EventType);
    ~Test() override;
    void setEventType(sf::Event::EventType);
    void setText(std::string);
    void update() override;
    sf::Event::EventType getEventType() const;
    void atInput(const sf::Event&, float);
    void moveRight(const sf::Event&, float);
    void moveLeft(const sf::Event&, float);
    void moveUp(const sf::Event&, float);
    void moveDown(const sf::Event&, float);

    std::vector<std::tuple<sf::Event::EventType, sf::Keyboard::Key, inputHandlerFunktion>>
    giveEventListner() override;
private:
    sf::Event::EventType eventType;
    float velocity;
};
