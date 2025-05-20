#pragma once
#include <SFML/System/Clock.hpp>

class Time {
public:
    Time(float);
    void restartDeltaClock();
    float getDeltaTime();
    float getWholeTime();



private:
    sf::Clock wholeTimeClock;
    sf::Clock deltaTimeClock;
    float wholeTime;
};
