#include "DrawingManager.h"


DrawingManager::DrawingManager(sf::RenderWindow &window, std::vector<std::shared_ptr<Drawable>>& drawings)
    : window(window), drawings(drawings) {
}


void DrawingManager::draw() {
    for (std::shared_ptr<Drawable> drawable : drawings) {
        window.draw(drawable->draw());
    }

}

void DrawingManager::setDrawings(const std::shared_ptr<Drawable> drawable) {
    drawings.push_back(drawable);
}

