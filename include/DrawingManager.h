#pragma once
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Drawable.h"

class DrawingManager {

public:
    explicit DrawingManager(sf::RenderWindow&);
    void draw();
    void setDrawings(std::shared_ptr<Drawable>);
    std::vector<std::shared_ptr<Drawable>> getDrawings();
private:
    std::vector<std::shared_ptr<Drawable>> drawings;
    sf::RenderWindow& window;


};
