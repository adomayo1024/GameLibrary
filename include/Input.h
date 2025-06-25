#pragma once
#include <SFML/Window/Event.hpp>

namespace myGE {
    /**
     * Ein Input stellt eine Aktion dar, die vom Fenster registriert wird
     */
    class Input : public sf::Event {
      public:
        
        /**
         * Konstruktor, um einen Input zu erstellen.
         * Alle Parameter sind optional, außer der Type des Inputs.
         * @param type
         * @param key
         * @param alt
         * @param shift
         * @param ctr
         * @param system
         * @param mouseButton
         * @param joyStickButton
         * @param joyStickId
         */
        // TODO ein Struct für parameter übergabe, für besser optionale Parameter
        Input(sf::Event::EventType type,
              sf::Keyboard::Key key = sf::Keyboard::Key::Unknown,
              bool alt = false,
              bool shift = false,
              bool ctr = false,
              bool system = false,
              sf::Mouse::Button mouseButton = sf::Mouse::Button::ButtonCount,
              unsigned int joyStickButton = -1,
              unsigned int joyStickId = -1);
        /**
         * Die Equals Methode, ob zwei Inputs gleich sind.
         * Es kommt auf den Typ des Events an, wie die gleichhet überprüft wird.
         *
         */
        bool operator==(const Input& other);

        bool operator<(const Input& other);

      private:
        /**
         * Prüft, ob zwei Key Input gleich sind.
         * Sie sind gleich, wenn dieselbe Taste gedrückt wird, und zusätzlich noch alt,ctr,shift,system bei beiden
         * gleich gedrückt bzw. nicht gedrückt wird.
         * @param other der andere Input
         * @return true, wenn bei Key Inputs gleich sind. false, wenn nicht
         */
        bool keyEventEquals(const Input& other);

        /**
         * Gibt die natürliche Ordnung für zwei KeyEvents wieder.
         * Zuerst wird der Key genommen. Dananch die spezial Tasten, die dabei gedrückt werden können.
         * @param other der ander Input
         * @return true, wenn es kleiner als der andere ist. False, wenn sie gleich oder der andere kleiner ist.
         */
        bool keyEventSmallerThen(const Input& other);

        /**
         * Prüft, ob zwei MouseButton Inputs gleich sind.
         * Sie sind gleich, wenn bei beiden Inputs der gleiche Button gedrückt worden ist.
         * @param other der andere Input
         * @return true, wenn bei Mousebutton Inputs gleich sind. false, wenn nicht
         */
        bool mouseButtonEventEquals(const Input& other);

        /**
         * Prüft, ob zwei JoystickButton Inputs gleich sind.
         * Sie sind gleich, wenn bei beiden Inputs derselbe Button vom selben Controller gedruckt wurde.
         * @param other der andere Input
         * @return true, wenn bei JoystickButton Inputs gleich sind. False, wenn nicht
         */
        bool joystickButtonEventEquals(const Input& other);

        /**
         * Überprüft, ob zwei Joysticks gleich sind, bei einem Joystick Input.
         * @param other der andere Joystick Input
         * @return true, wenn bei den Joysticks bei den beiden Inputs derselbe ist. False wenn nicht.
         */
        bool joystickEquals(const Input& other);
    };

}

