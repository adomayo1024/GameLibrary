#include "MyTime.h"


namespace myGE {
    sf::Clock MyTime::wholeTimeClock{};
    sf::Clock MyTime::deltaTimeClock{};
    float MyTime::deltaTime = 0;
    float MyTime::timePass = 0;

}


float myGE::MyTime::getDeltaTime() {
    return deltaTime;
}

void myGE::MyTime::newFrame() {
    deltaTime = deltaTimeClock.restart().asMilliseconds();
    deltaTimeClock.restart();
}

float myGE::MyTime::getWholeTime() {
    return wholeTimeClock.getElapsedTime().asSeconds() + timePass;
}

float myGE::MyTime::getWholeTimeThisSession() {
    return wholeTimeClock.getElapsedTime().asMilliseconds();
}

void myGE::MyTime::setWholeTime(float aTimePass) {
    timePass = aTimePass;
}


void myGE::MyTime::restartDeltaClock() {
    deltaTimeClock.restart();
}
