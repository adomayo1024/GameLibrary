#pragma once
#include <gmock/gmock.h>
#include "Inputable.h"
#include <vector>
#include <tuple>


class InputableMock : public myGE::Inputable {
    public:
    std::vector<std::tuple<EventType, Key, inputHandlerFunktion>>
    giveEventListner() override;
    MOCK_METHOD(void, mockKey, (const sf::Event& event, float deltaTime));
    MOCK_METHOD(void, mockNotKey, (const sf::Event& event, float deltaTime));

};


