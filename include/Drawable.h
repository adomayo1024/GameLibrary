#pragma once
#include <SFML/Graphics/Drawable.hpp>

/**
 * Ein Drawable ist ein Objekt welches auf ein SFML-Window gezeichnet werden kann.
 */

class Drawable {
public:

    Drawable() = default;
    virtual ~Drawable() = default;

    /**
     * Die Funktion die aufgerufen wird, wenn das Objekt gedrwat werden soll.
     * return: Gibt das sf::Drawable zurück welches dann auf das Winow gemalt werden soll
     */
    virtual sf::Drawable& draw() = 0;

    /**
     * Aktiviert oder deaktiviert, ob es gerade gemalt werden soll.
     */
    void switchActivity() {active %= 1;}

    /**
     *Gibt die Aktivität wieder, ob es gemalt werden soll
     */
    bool isActive() const {return active;}

    private:
    /**
     *Variable die beschreibt, ob das Objekt gemalt werden soll
     */
    bool active = true;
};
