#pragma once
#include <functional>
#include <map>
#include <vector>
#include <SFML/Window/Event.hpp>

#include "Input.h"
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
     * Konstruktor der ein InputManager Objekt instanziiert. Und schon Objekte für Inputs anmeldet.
     * @param anmeldungsTupelListe liste mit den Anmeldungen für bestimmte Inputs
     */
    explicit InputManager(std::vector<
    std::tuple<
    Input,
    inputHandlerFunktion>>& anmeldungsTupelListe);

    /**
     * Gibt den übergebenen Input an die Objekte weiter, die sich dafür angemeldet haben.
     * Wenn es sich um Pressed Input handelt, wird der Button/Key nur als gedrückt registriert, aber noch nicht
     * an die Objekte weiter geleitet.
     * @param input der Input der vom Window gemeldet wurden ist
     * @param deltaTime die Zeit, die für den letzten Frame gebraucht wurde, zu berechnen
     */
    void manage(Input &input, float deltaTime);

    /**
     * Hier melden sich Elemente an, für einen bestimmten Input
     * @param anmeldungsTupel das Tupel beinhaltet einmal den Input sowie die Funktion, die dann aufgerufen werden soll
     */
    void setListner(std::tuple<
        Input,
        inputHandlerFunktion> anmeldungsTupel);

    /**
     * Hier melden sich Elemente an, für einen bestimmten Input
     * @param anmeldungsTupelListe die Liste beinhaltet Tupel, welche spezifizieren, welches Element, sich
     * für welchen Input anmelden möchte.
     * Die Tupel beinhalten den Input sowie die Funktion, die dann aufgerufen werden soll.
     */
    void setListners(std::vector<
    std::tuple<
    Input,
    inputHandlerFunktion>>& anmeldungsTupelListe);

    /**
     * Die Funktion handeled nochmal seperat alle Key die derzeitig gedrückt werden, und im letzten Frame nicht losgelassen wurden sind
     * @param deltaTime die Zeit, die es gebraucht hat, den letzten Frame zu berechnen.
     */
    void handleStillPressedKeys(float deltaTime);

private:
    /**
     * Map die extra für alle Key Events die Anmeldungen der Objekt speichert, zusätzlich noch die spezifischen Keys.
     */
    std::map<sf::Event::EventType, std::map<sf::Keyboard::Key,
    std::vector<inputHandlerFunktion>>> keyMap;

    /**
     * Die Map die für jeden Input die Funktionen hält, die die Objekte angemeldet haben, für den jeweiligen Input
     */
    std::map<Input, std::vector<inputHandlerFunktion>> listners;

    /**
     * Alle TestKlasse die auf die Member Variblen Zugreifen dürfen
     */
    friend class InputManagerTest_InitializeWithNothing_Test;
    friend class InputManagerTest_InitializeWithElements_Test;

};
}