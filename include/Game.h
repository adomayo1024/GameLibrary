#pragma once
#include <DrawingManager.h>
#include <InputManager.h>
#include <UpdateManager.h>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Element.h"
#include "Time.h"

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
    void update();
    void handleInput(sf::Event& event);
    void handleStillPressedKeys();
    void save();
    void newFrame();
    void makeGameObject(std::string pfadName);

    void init();
    GameState getCurrentState() const;
private:
    sf::RenderWindow window;
    bool running = true;
    GameState currentState = GameState::TITLE_SCREEN;
    DrawingManager drawing_manager;
    UpdateManager update_manager;
    InputManager input_manager;
    std::vector<std::shared_ptr<Element>> gameElements;
    Time time;


};

