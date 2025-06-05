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
     * Konstruktor der ein Time Objekt instanziiert
     * @param wholePassTime die Zeit die schon insgesamt bis her im Spiel verbracht wurde.
     */
    explicit MyTime(float wholePassTime);

    /**
     * Dekonstruktor
     */
    ~MyTime();

    /**
     * Wird nach jedem Frame aufgerufen und starte die DeltaClock neu, die misst wie lang ein Frame dauert
     */
    void restartDeltaClock();

    /**
     * Gibt die Zeit zurück wie lange der letzte Frame gebraucht hat.
     * @return Zeit die der letzte Frame gebraucht hat
     */
    float getDeltaTime();

    /**
     * Gibt die bisherige gesamt Zeit die in dem Spiel verbracht wurde
     * @return gesamt Verbrachte Zeit im Spiel
     */
    float getWholeTime();

    /**
     * Gibt die Zeit wieder wie lange die bisherige Session an dauert, wie lange spielt man schon,
     * seid den man es das letzte mal gestartet hat
     * @return zeit die vergangen seid man das Spiel gestartet hat
     */
    float getWholeTimeThisSession();

    /**
     * Setzt am Anfang beim Starten die gesamt Zeit auf den richtigen Wert
     */
    void setWholeTime(float);

    /**
     * Wird am Anfang jedes Fram aufgerufen, und speichert, wie lange der letzte Frame gebraucht hat
     * und sonstige Uhren die nach jedem Frame geneustartet werden sollen.
     */
    void newFrame();

private:
    /**
     * Clock die gesamt Zeit miss
     */
    sf::Clock wholeTimeClock;

    /**
     * Clock die die Zeit pro Frame misst
     */
    sf::Clock deltaTimeClock;

    /**
     * Speichert die Zeit des letzten Frames
     */
    float deltaTime;

    /**
     * Zeit die vor der aktuellen Session schon im Spiel verbracht wurde
     */
    float timePass;
};
}