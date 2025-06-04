#include "../include/DrawingManager.h"


myGE::DrawingManager::DrawingManager(sf::RenderWindow &window)
    : window(window), drawings(std::vector<std::shared_ptr<Drawable>>{}) {
}


void myGE::DrawingManager::draw() {
    for (const std::shared_ptr<Drawable>& drawing : drawings) {
        if (drawing->isActive()) {
            window.draw(drawing->draw());
        }
    }

}

void myGE::DrawingManager::setDrawings(const std::shared_ptr<Drawable> drawable) {
    drawings.push_back(drawable);
}

std::vector<std::shared_ptr<myGE::Drawable>> myGE::DrawingManager::getDrawings() {
    return drawings;
}

