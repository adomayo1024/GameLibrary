#include "MYTime.h"

#include <iostream>
#include <ostream>

myGE::MyTime::MyTime(float passTime) : wholeTimeClock(sf::Clock{}), deltaTimeClock(sf::Clock{}), timePass(passTime){
}

myGE::MyTime::~MyTime() {
    std::cout << wholeTimeClock.getElapsedTime().asSeconds() << std::endl;
}

float myGE::MyTime::getDeltaTime() {
    return deltaTime;
}

void myGE::MyTime::newFrame() {
    deltaTime = deltaTimeClock.restart().asSeconds();
    deltaTimeClock.restart();
}

float myGE::MyTime::getWholeTime() {
    return wholeTimeClock.getElapsedTime().asSeconds() + timePass;
}

float myGE::MyTime::getWholeTimeThisSession() {
    return wholeTimeClock.getElapsedTime().asSeconds();
}

void myGE::MyTime::setWholeTime(float timePass) {
    this->timePass = timePass;
}


void myGE::MyTime::restartDeltaClock() {
    deltaTimeClock.restart();
}