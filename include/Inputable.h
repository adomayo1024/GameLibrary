#pragma once
#include "InputManager.h"
#include "TypBenenungen.h"

class Inputable {
    public:
    Inputable() = default;
    virtual ~Inputable() = default;
    void switchActivity() {active %= 1;}
    bool isActive() const {return active;}
    virtual std::vector<std::tuple<EventType, Key, inputHandlerFunktion>>
    giveEventListner() = 0;
protected:
    bool active = true;
    float timeLastFrame = 0;
};
