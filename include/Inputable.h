#pragma once
#include "InputManager.h"
#include "TypBenenungen.h"

namespace myGE {

/**
 * Ein Inputable ist eine abstrakte Klasse, welche Objekte beschreibt, die bestimmte Inputs vom Spieler verarbeiten kann.
 */
class Inputable {
public:
    Inputable() = default;
    virtual ~Inputable() = default;

    /**
     * Verändert die Aktivität des Objekts.
     */
    void switchActivity() {active %= 1;}

    /**
     * Gibt wieder, ob das Objekt derzeitig aktiv ist.
     * @return true, wenn aktiv. False wenn inaktiv
     */
    bool isActive() const {return active;}

    /**
     * Return eine Liste mit Tupels, welche den Event Typ beinhalten, mit der Funktion die bei diesem Event aufgerufen werden soll.
     * Wenn der EventType ein key Event ist, ist das zweite Element der jeweilige Key, wenn es kein Key gibt, ist es Unknown
     * @return Liste mit Tupel der EventType, Key, und Funktion
     */
    virtual std::vector<std::tuple<EventType, Key, inputHandlerFunktion>>
    giveEventListner() = 0;
protected:
    /**
     * Boolean, ob das Objekt aktiv für Inputable ist.
     * Wenn inaktiv, dann will es nicht auf Event reagieren.
     */
    bool active = true;

    /**
     * Tote Variable  //TODO Variable löschen
     */
    float timeLastFrame = 0;
};
}