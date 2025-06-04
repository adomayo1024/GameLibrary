#pragma once

#include "Drawable.h"
#include "Updatable.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>

namespace myGE {
/**
 * Ein Element ist ein element im Spiel welches gemalt und geupdatet werden kann.
 */
class Element: public myGE::Drawable,
               public Updatable{

public:
    /**
     * Konstrukur für die Initialisierung eines Element Objekts
     * @param path der path zum Bild für die Textur
     */
    explicit Element(std::string path);

    /**
     * Gibt das Sprite objekt zurück des Elements
     * @return sf::Sprite objekt des Elements
     */
    sf::Sprite& getSprite();

    /**
     * Überschreibt die draw Funktion von drawable
     * @return das sf::Drawable objekt
     */
    sf::Drawable& draw() override;

    /**
     * Überschreibt, die update Funktion von updatable
     */
    void update() override = 0;

protected:
    /**
     * Sprite Objekt für das Element
     */
    sf::Sprite sprite;

    /**
     * Der Path für das Bild der Textur
    */
    std::string texturePath;

    /**
     * Die Texture des Elements
     */
    sf::Texture& texture;


    sf::Clock deltaClock;

};
}