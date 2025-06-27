#pragma once

#include <string>
#include <vector>
#include <SFML/Window/Event.hpp>
#include "Element.h"
#include "Inputable.h"


class Test : public myGE::Element, public myGE::Inputable{
public:
    explicit Test(std::string);
    ~Test() override;
    void setText(std::string);
    void update() override;
    void atInput(const sf::Event&, float);
    void moveRight(const sf::Event&, float);
    void moveLeft(const sf::Event&, float);
    void moveUp(const sf::Event&, float);
    void moveDown(const sf::Event&, float);

    std::vector<std::tuple<myGE::Input, inputHandlerFunktion>>
    giveEventListner() override;
private:
    float velocity;
};
