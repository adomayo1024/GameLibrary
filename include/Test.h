#pragma once


#include <iosfwd>
#include <iosfwd>
#include <iosfwd>
#include <iosfwd>
#include <string>
#include <vector>
#include <vector>
#include <vector>
#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include "Element.h"
#include "Inputable.h"
#include "InputManager.h"


class Test : public Element, public Inputable{
public:
    explicit Test(std::string, sf::Event::EventType);
    ~Test() override;
    void setEventType(sf::Event::EventType);
    void setText(std::string);
    void update() override;
    sf::Event::EventType getEventType() const;
    void atInput(const sf::Event&);
    void moveRight(const sf::Event&);
    void moveLeft(const sf::Event&);
    void moveUp(const sf::Event&);
    void moveDown(const sf::Event&);

    std::vector<std::tuple<sf::Event::EventType, sf::Keyboard::Key, std::function<void(const sf::Event &) >>>
    giveEventListner() override;
private:
    sf::Event::EventType eventType;
    float velocity;
};
