#pragma once


#include <string>
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
    void setListners(InputManager&) override;
private:
    sf::Event::EventType eventType;
};
