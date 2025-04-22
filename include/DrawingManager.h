#pragma once
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Drawable.h"

class DrawingManager {

public:
    DrawingManager(sf::RenderWindow&);
    void draw();
    void setDrawings(const std::shared_ptr<Drawable>&);
private:
    std::vector<std::shared_ptr<Drawable>> drawings;
    sf::RenderWindow& window;


};
