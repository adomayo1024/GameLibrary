#pragma once
#include "InputManager.h"

class Inputable {
    public:
    Inputable() = default;
    virtual ~Inputable() = default;
    void switchActivity() {active %= 1;}
    bool isActive() const {return active;}
    virtual void setListners(InputManager&) = 0;
private:
    bool active = false;
};
