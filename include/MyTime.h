#pragma once
#include <SFML/System/Clock.hpp>

namespace myGE {
    // TODO mache Time singleTone mabey komplett static
/**
 * Die Klasse managed und misst alle Sachen die mit Zeit zutuen hat.
 * In jedem Game sollte nur ein Objekt exestieren.
 * Jedes Objekt kann sich auch seine eigene Clock starten.
 */
class MyTime {
public:

    /**
     * Wird nach jedem Frame aufgerufen und starte die DeltaClock neu, die misst wie lang ein Frame dauert
     */
    static void restartDeltaClock();

    /**
     * Gibt die Zeit zurück wie lange der letzte Frame gebraucht hat.
     * @return Zeit die der letzte Frame gebraucht hat
     */
    static float getDeltaTime();

    /**
     * Gibt die bisherige gesamt Zeit die in dem Spiel verbracht wurde
     * @return gesamt Verbrachte Zeit im Spiel
     */
    static float getWholeTime();

    /**
     * Gibt die Zeit wieder wie lange die bisherige Session an dauert, wie lange spielt man schon,
     * seid den man es das letzte mal gestartet hat
     * @return zeit die vergangen seid man das Spiel gestartet hat
     */
    static float getWholeTimeThisSession();

    /**
     * Setzt am Anfang beim Starten die gesamt Zeit auf den richtigen Wert
     */
    static void setWholeTime(float);

    /**
     * Wird am Anfang jedes Fram aufgerufen, und speichert, wie lange der letzte Frame gebraucht hat
     * und sonstige Uhren die nach jedem Frame geneustartet werden sollen.
     */
    static void newFrame();

private:
    /**
     * Clock die gesamt Zeit miss
     */
    static sf::Clock wholeTimeClock;

    /**
     * Clock die die Zeit pro Frame misst
     */
    static sf::Clock deltaTimeClock;

    /**
     * Speichert die Zeit des letzten Frames
     */
    static float deltaTime;

    /**
     * Zeit die vor der aktuellen Session schon im Spiel verbracht wurde
     */
    static float timePass;
};
}