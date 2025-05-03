#pragma once

class Inputable {
    public:
    Inputable() = default;
    virtual ~Inputable() = default;
    void switchActivity() {active %= 1;}
    bool isActive() const {return active;}

private:
    bool active = false;
};
