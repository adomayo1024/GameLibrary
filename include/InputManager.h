#pragma once
#include <functional>
#include <map>
#include <vector>
#include <SFML/Window/Event.hpp>
#include "TypBenenungen.h"

namespace myGE {
/**
 * Der InputManager handeled alle Inputs die von einem SFML-Window kommen und gibt diese an die Objekt weiter,
 * die sie benötigen.
 */
class InputManager {
public:
    /**
     * Konstruktor der ein InputManager Objekt instanziiert.
     */
    explicit InputManager();

    /**
     * Gibt das übergebene Event an die Objekt weiter die sich dafür angemeldet haben.
     * @param event das Event was ausgelöst wurden ist und welches behandelt werden soll
     * @param deltaTime die Zeit die für den letzten Frame gebraucht wurde zu berechnen
     */
    void manage(sf::Event &event, float deltaTime);

    /**
     * Hier melden sich objekt an, für ein bestimmtes Event
     * @param anmeldungsTupel das Tupel beinhaltet den EventType, zu welches es benachrichtige werden will,
     * wenn es ein Key Event ist gibt Key den Key an, wenn es kein Key Event ist soll das hier None sein,
     * inputHandlerFunktion ist die spezifische Funktion des Objekts die aufgerufen werden soll, wenn das Event ausgelöst wurden ist
     */
    void setListner(std::tuple<
        EventType,
        Key,
        inputHandlerFunktion> anmeldungsTupel);

    /**
     * Hier melden sich objekt an, für ein bestimmtes Event
     * @param anmeldungsTupelListe die Liste beinhaltet Tupel, welche spezifiezieren welches Objekt sich
     * sich für welches Event anmelden möchte.
     * Die Tupel beinhalten den EventType, zu welches es benachrichtige werden will,
     * wenn es ein Key Event ist gibt Key den Key an, wenn es kein Key Event ist soll das hier None sein,
     * inputHandlerFunktion ist die spezifische Funktion des Objekts die aufgerufen werden soll, wenn das Event ausgelöst wurden ist
     */
    void setListners(std::vector<
    std::tuple<
    EventType,
    Key,
    inputHandlerFunktion>>& anmeldungsTupelListe);

    /**
     * Die Funktion handeled nochmal seperat alle Key die derzeitig gedrückt werden, und im letzten Frame nich losgelassen wurden sind
     * @param deltaTime die Zeit die es gebraucht hat den letzten Frame zu berechnen.
     */
    void handleStillPressedKeys(float deltaTime);

private:
    /**
     * Die Map die die Anmeldungen der OBjekt zu den jeweiligen Events speichert
     */
    std::map<sf::Event::EventType,
    std::vector<inputHandlerFunktion>> listnerMap;
    /**
     * Map die extra für alle Key Events die Anmeldungen der Objekt speichert, zusätzlich noch die spezifischen Keys.
     */
    std::map<sf::Event::EventType, std::map<sf::Keyboard::Key,
    std::vector<inputHandlerFunktion>>> keyMap;
};
}