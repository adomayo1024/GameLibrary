#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class Game {

public:
    explicit Game(int width, int height);
    const sf::RenderWindow& getWindow() const;
    void endGame();
    bool isRunning() const;
private:
    sf::RenderWindow window;
    bool running = true;

};

/*
{
    1, 1, 1, 1, 0, 0, 0
    1, 0, 0, 0, 1, 0, 1
    0, 1, 1, 0, 0, 2, 1
    0, 0, 0, 1, 1, 0, 0
}
*/
