#pragma once
#include <SFML/System/Clock.hpp>

namespace myGE {

class MyTime {
public:
    explicit MyTime(float);
    ~MyTime();
    void restartDeltaClock();
    float getDeltaTime();
    float getWholeTime();
    float getWholeTimeThisSession();
    void setWholeTime(float);
    void newFrame();

private:
    sf::Clock wholeTimeClock;
    sf::Clock deltaTimeClock;
    float deltaTime;
    float timePass;
};
}