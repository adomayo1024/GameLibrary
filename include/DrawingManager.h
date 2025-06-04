#pragma once
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Drawable.h"

namespace myGE {

/**
 * Enum welche die verschiedenen Tiefen repräsentiert, wann etwas gezeichnet werden soll.
 * (Wird wahrscheinlich aber noch ersetzt so dass ich eine undefinierte Anzahl an Layern habe)
 */
enum class LAYER {
    FARBACKGROUND,
    BACKGROUND,
    MIDDLEGROUND,
    FOREGROUND,
    NEARFOREGROUND
};
/**
 * Die Klasse die alle Drawable Objekt managed und diese dann auch auf das Window malt
 */
class DrawingManager {

public:
    /**
     * Konstruktor der ein DrawingManager Objekt initialisiert
     * @param: window das Window auf das gemalt werden soll
     */
    explicit DrawingManager(sf::RenderWindow& window);

    /**
     * Malt alle Objekt die es managed und und aktiv sind auf das Window
     */
    void draw();

    /**
     * Hier werden Drawable Objekte angemeldet  die auf das Window gemalt werden sollen
     */
    void setDrawings(std::shared_ptr<myGE::Drawable>);
    std::vector<std::shared_ptr<myGE::Drawable>> getDrawings();
private:
    /**
     * Dieser Vector hält alle Drawable Objekte die vom Drawing Manager gemanaged werden.
     * Der Vektor hält diese als shared_pointer um Polymorphism zu bewerkstelligen.
     */
    std::vector<std::shared_ptr<myGE::Drawable>> drawings;

    /**
     * Das Window wo drauf der DrawingManager alles drauf malt
     */
    sf::RenderWindow& window;


};
}
