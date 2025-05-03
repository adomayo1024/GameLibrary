#pragma once

class Inputable {
    public:
    Inputable() = default;
    virtual ~Inputable() = default;
    void switchActivity() {active %= 1;}
private:
    bool active = false;
};
