#include "Game.h"


Game::Game(int width, int heigth) :
window(sf::RenderWindow{sf::VideoMode(width, heigth), "Moon"}) {

}

const sf::RenderWindow& Game::getWindow() const {
    return window;
}

void Game::endGame() {
    running = false;
    window.close();
}

bool Game::isRunning() const {
    return running;
}