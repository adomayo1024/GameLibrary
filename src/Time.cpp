#include "../include/Time.h"

#include <iostream>
#include <ostream>

Time::Time(float passTime) : wholeTimeClock(sf::Clock{}), deltaTimeClock(sf::Clock{}), timePass(passTime){
}

Time::~Time() {
    std::cout << wholeTimeClock.getElapsedTime().asSeconds() << std::endl;
}

float Time::getDeltaTime() {
    return deltaTime;
}

void Time::newFrame() {
    deltaTime = deltaTimeClock.restart().asSeconds();
    deltaTimeClock.restart();
}

float Time::getWholeTime() {
    return wholeTimeClock.getElapsedTime().asSeconds() + timePass;
}

float Time::getWholeTimeThisSession() {
    return wholeTimeClock.getElapsedTime().asSeconds();
}

void Time::setWholeTime(float timePass) {
    this->timePass = timePass;
}


void Time::restartDeltaClock() {
    deltaTimeClock.restart();
}