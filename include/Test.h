#pragma once


#include "Drawable.h"
#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>

#include "Updatable.h"


class Test : public Drawable,
             public Updatable{
public:
    explicit Test(std::string, sf::Sprite&, sf::Event::EventType);
    Test(const Test&);
    ~Test();
    void setEventType(sf::Event::EventType);
    void setText(std::string);
    sf::Sprite& getSprite() const;
    sf::Drawable& draw() override;
    void update() override;
    sf::Event::EventType getEventType() const;
    void atInput(const sf::Event&);
private:
    std::string text;
    sf::Sprite& sprite;
    sf::Event::EventType eventType;
};
