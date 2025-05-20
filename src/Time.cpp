#include "../include/Time.h"

Time::Time(float passTime) : wholeTimeClock(sf::Clock{}), deltaTimeClock(sf::Clock{}), wholeTime(passTime) {

}

float Time::getDeltaTime() {
    return deltaTimeClock.getElapsedTime().asSeconds();
}

float Time::getWholeTime() {
    return wholeTimeClock.getElapsedTime().asSeconds() + wholeTime;
}

void Time::restartDeltaClock() {
    deltaTimeClock.restart();
}