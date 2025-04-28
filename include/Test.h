#pragma once


#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include "Element.h"


class Test : public Element{
public:
    explicit Test(std::string, sf::Event::EventType);
    ~Test();
    void setEventType(sf::Event::EventType);
    void setText(std::string);
    void update() override;
    sf::Event::EventType getEventType() const;
    void atInput(const sf::Event&);
private:
    sf::Event::EventType eventType;
};
