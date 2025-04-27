#pragma once
#include <DrawingManager.h>
#include <InputManager.h>
#include <UpdateManager.h>
#include <SFML/Graphics/RenderWindow.hpp>

enum class GameState {
    MENU, TITLE_SCREEN, PLAYING
};

class Game {

public:
    explicit Game(int width, int height, const std::string& title = "Moon");
    sf::RenderWindow& getWindow();
    void endGame();
    bool isRunning() const;
    bool getLastEvent(sf::Event& event);
    void draw();
    void handleInput(sf::Event& event);
    void init();
    GameState getCurrentState() const;
private:
    sf::RenderWindow window;
    bool running = true;
    GameState currentState = GameState::TITLE_SCREEN;
    DrawingManager drawing_manager;
    UpdateManager update_manager;
    InputManager input_manager;


};

