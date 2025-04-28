#include "../include/DrawingManager.h"


DrawingManager::DrawingManager(sf::RenderWindow &window)
    : window(window), drawings(std::vector<std::shared_ptr<Drawable>>{}) {
}


void DrawingManager::draw() {
    for (const std::shared_ptr<Drawable>& drawing : drawings) {
        window.draw(drawing->draw());
    }

}

void DrawingManager::setDrawings(const std::shared_ptr<Drawable> drawable) {
    drawings.push_back(drawable);
}

std::vector<std::shared_ptr<Drawable>> DrawingManager::getDrawings() {
    return drawings;
}

