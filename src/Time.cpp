#include "../include/Time.h"

#include <iostream>
#include <ostream>

myGE::Time::Time(float passTime) : wholeTimeClock(sf::Clock{}), deltaTimeClock(sf::Clock{}), timePass(passTime){
}

myGE::Time::~Time() {
    std::cout << wholeTimeClock.getElapsedTime().asSeconds() << std::endl;
}

float myGE::Time::getDeltaTime() {
    return deltaTime;
}

void myGE::Time::newFrame() {
    deltaTime = deltaTimeClock.restart().asSeconds();
    deltaTimeClock.restart();
}

float myGE::Time::getWholeTime() {
    return wholeTimeClock.getElapsedTime().asSeconds() + timePass;
}

float myGE::Time::getWholeTimeThisSession() {
    return wholeTimeClock.getElapsedTime().asSeconds();
}

void myGE::Time::setWholeTime(float timePass) {
    this->timePass = timePass;
}


void myGE::Time::restartDeltaClock() {
    deltaTimeClock.restart();
}