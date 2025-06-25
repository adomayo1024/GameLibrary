#pragma once
#include <SFML/Window/Event.hpp>

namespace myGE {
    /**
     * Ein Input stellt eine Aktion darr, die vom Fenster registriert wird
     */
    class Input : public sf::Event {
      public:
        Input();
        /**
         * Die Equals Methode ob zwei Inputs gleich sind.
         * Es kommt auf den Typ des Events an wie die gleichhet überprüft wird.
         *
         */
        bool operator==(const Input& other);

        bool operator<(const Input& other);

      private:
        /**
         * Prüft ob zwei Key Input gleich sind.
         * Sie sind gleich, wenn die selbe Taste gedrückt wird, und zusätzlich noch alt,ctr,shift,system bei beiden
         * gleich gedrückt bzw. nicht gedrückt wird.
         * @param other der andere Input
         * @return true, wenn bei Key Inputs gleich sind. false, wenn nicht
         */
        bool keyEventEquals(const Input& other);

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

