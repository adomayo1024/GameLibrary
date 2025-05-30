#pragma once
#include <map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>

#include "TypBenenungen.h"

/**
 * Speichert alle möglichen Sachen im Spiel, wie schon geladenen Texturen, oder derzeitig gedrückte Keys
 */
class Storage {

public:

    Storage() = default;

    /**
     * Gibt die Texture wieder mit den angegebenen Path.
     * Wenn es die Texture mit diesen Path nicht gibt, wird diese erstellt und gespeichert.
     * @return das sf::Texture Objekt, die die Texture mit diesen Path enthält
     */
    static sf::Texture& getTexture(std::string path);

    /**
     * Gibt eine Map zurück mit derzeitig allen gedrückten Keys auf der Tastatur, mit einer Clock die angibt wie lange
     * der Key schon gedrückt wird.
     * @return Map mit Keys und zugehörigen Clock
     */
    static const std::map<Key, sf::Clock> getPressedKeys();

    /**
     * Speichert den Key als gedrückt
     * @param key der Key der gedrückt wurde und gespeichert werden soll
     */
    static void addKey(Key key);

    /**
     * Überprüft ob der Key derzeitig gedrückt wird
     * @param key der Key der überprüft werden soll
     * @return true wenn der key derzeitig gedrückt wird
     */
    static bool containsKey(Key key);

    /**
     * Gibt an, ob derzeitig irgendein Key gedrückt wird
     * @return true wird mindestens 1 Key gedrückt wird
     */
    static bool areAnyKeysPressed();

    /**
     * Gibt die Clock wieder die angibt wie lange der Key schon gedrückt wird
     * @param key der Key von den man wissen will wie lange der schon gedrückt wird
     * @return die Clock, die die Zeit misst wie lange der Key schon gedrückt wird
     */
    static sf::Clock& getClock(Key key);

    /**
     * Entfernt den Key aus der Map, also wird dieser Key nicht mehr gedrückt
     * @param key der Key der nicht mehr gedrückt wird
     */
    static void removeKey(Key key);

private:
    /**
     * Die Map die alle derzeitigen Texture speichert
     */
    static std::map<std::string, sf::Texture> textureSaves;
    /**
     * die Map die alle derzeitig gedrückten Key speichert
     */
    static std::map<Key, sf::Clock> keyClocks;
};
