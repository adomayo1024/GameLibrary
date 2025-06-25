#pragma once
#include "DrawingManager.h"
#include "InputManager.h"
#include "UpdateManager.h"
#include <SFML/Graphics/RenderWindow.hpp>

#include "Element.h"
#include "MyTime.h"

namespace myGE {
/**
 * Enum das die verschieden Spiel-States beschreibt.
 * MENU: Man befindet sich derzeit in einem Menü (Hauptmenü, Pause menü etc:)
 * TITLE_SCREEN: Man befindet sich im Title Screen.
 * PLAYING: Man ist im Gameplay, man spielt.
 */
enum class GameState {
    MENU, TITLE_SCREEN, PLAYING
};

/**
 * Die Game-Klasse ist main Klasse wo alles gehalten wird, und alle Spielinformation enthalten sind.
 * Wie das SFML-Window, alle Manger etc.
 */
class Game {

public:
    /**
     * Der Konstruktor der das Game Objekt initialisiert.
     * @param width Die Breite des SFML-Windows
     * @param height Die höhe des SFML-Windows
     * @param title Der Title des SFML-Winows
     */
    explicit Game(int width, int height, const std::string& title = "Moon");

    /**
     * Getter Methode für das SFML-Window
     * @return das SFML-Window
    */
    sf::RenderWindow& getWindow();

    /**
     * Methode, die das Spiel beendet und allerletzte Sachen aufräumt
     */
    void endGame();

    /**
     * Gibt wieder, ob das Spiel noch läuft
     * @return true wenn es noch läuft. False wenn es nicht mehr läuft
     */
    bool isRunning() const;

    /**
     * Gibt das letzte Input Event wieder, was das SFML-Window erhalten hat.
     * @param event Referenzparameter, der nach der Methode das Event enthält, wenn eins passiert it.
     * @return true, wenn ein Event passiert ist. False, wenn keins passiert ist.
     */
    bool getLastEvent(Input input);

    /**
     * Malt den aktuellen Frame auf das SFML-Window
     */
    void draw();

    /**
     * Alle Game Objekt werden geupdated
     */
    void update();

    /**
     * Wenn ein Event passiert ist, wird es hier bearbeitet, durch den Input-Manager.
     * Wenn es aber ein key Event ist, dann wird der Key hier nur als gedrückt registriert, oder entnommen von der
     * gedrückten Keys. Die eigentliche bearbeitung folgt in der Methode "handleStillPressedKeys".
     * @param event das Event was gehandelt werden soll
     */
    void handleInput(Input input);

    /**
     * Hier werden alle derzeit gedrückten Keys bearbeitet.
     */
    void handleStillPressedKeys();


    /**
     * Speichert den derzeitigen Spielstand.
     */
    void save();

    /**
     * Wird am Anfang jedes Frames aufgerufen, und führt Sachen, aus die jeden Frame gemacht werden müssen.
     * Wie die Uhr zu restarten die, die Delta-time misst.
     */
    void newFrame();

    /**
     * Derzitige Hilfsmethode um ein Game Obejkt zu erzeugen und ihn für alle Manger anzumelden.
     * @param pfadName Der Pfadname für die Texture des Game Objekts
     */
    void makeGameObject(std::string pfadName);

    /**
     * Initilisiert das Spielt. Erzeugt alle Game objekt die es am Anfang braucht etc.
     */
    void init();

    /**
     * Gibt den derzeitigen Spiel-State wieder.
     */
    GameState getCurrentState() const;
private:
    /**
     * Das SFML-Window
     */
    sf::RenderWindow window;

    /**
     * Boolean, ob das Spiel noch läuft oder nicht
     */
    bool running = true;

    /**
     * Der derzeitige Spiel-State
     */
    GameState currentState = GameState::TITLE_SCREEN;

    /**
     * Der DrawingManger, der die Sachen auf das SFML-Window malt.
     */
    myGE::DrawingManager drawing_manager;

    /**
     * Der UpdateManger, der dafür da ist alle Game objekt zu updaten
     */
    UpdateManager update_manager;

    /**
     * Der InputManager, der dafür da ist, jeden Input zu handlen.
     */
    InputManager input_manager;

    /**
     * Liste mit allen Game Objekten.
     */
    std::vector<std::shared_ptr<myGE::Element>> gameElements;

    /**
     * Time Objekt was für alles zuständig ist, was mit Zeit zu tun hat.
     */
    MyTime time;


};
}
