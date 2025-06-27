#pragma once
#include <SFML/Window/Event.hpp>

namespace myGE {
    /**
     * Die Klasse Input repräsentiert Eingaben (wie Tasten- und Mausaktionen) und erweitert die Eigenschaften des SFML Events.
     */
    class Input : public sf::Event {
    public:
        struct ParameterInputKonstruktor {
            sf::Event::EventType type;
            sf::Keyboard::Key key = sf::Keyboard::Key::Unknown;
            bool alt = false;
            bool shift = false;
            bool ctr = false;
            bool system = false;
            sf::Mouse::Button mouseButton = sf::Mouse::Button::ButtonCount;
            unsigned int joyStickButton = -1;
            unsigned int joyStickId = -1;
        };


        Input() = default;
        ~Input() = default;

        /**
         * Konstruktor, um einen Input zu erstellen, und mit eigenen Werten direkt zu versehen.
         * Alle Parameter sind optional, außer der Type des Inputs.
         * @param params
         */
        explicit Input(ParameterInputKonstruktor params);

        /**
         * Konstruktor, um einen Input zu erstellen, durch ein SFML event
         * @param event das SFML event welches der Input darstellen soll.
         */
        explicit Input(sf::Event event);

        /**
         * Kopierkonstruktor
         * @param input
         */
        Input(Input& input);

        /**
         * Die Equals Methode, ob zwei Inputs gleich sind.
         * Es kommt auf den Typ des Events an, wie die gleichhet überprüft wird.
         *
         */
        bool operator==(const Input &other) const;

        bool operator<(const Input &other) const;


        Input &operator=(const sf::Event event);

        /**
        * Überprüft, ob ein Input ein PressedInput ist.
        * Ein Input, wo einen Taste oder Button gedrückt wird.
        * @param input der Input, der überprüft werden soll
        * @return true, wenn es ein PressedInput ist. False, wenn nicht.
        */
        static bool isItPressedInput(const Input &input);

        /**
         * Überprüft, ob ein Input ein ReleasedInput ist.
         * Ein Input, wo eine Taste oder Button losgelassen wird.
         * @param input der Input, der überprüft werden soll
         * @return true, wenn es ein ReleasedInput ist. False, wenn nicht.
         */
        static bool isItReleasedInput(const Input &input);

    private:
        /**
         * Prüft, ob zwei Key Input gleich sind.
         * Sie sind gleich, wenn dieselbe Taste gedrückt wird, und zusätzlich noch alt,ctr,shift,system bei beiden
         * gleich gedrückt bzw. nicht gedrückt wird.
         * @param other der andere Input
         * @return true, wenn bei Key Inputs gleich sind. false, wenn nicht
         */
        bool keyEventEquals(const Input &other) const;

        /**
         * Gibt die natürliche Ordnung für zwei KeyEvents wieder.
         * Zuerst wird der Key genommen. Dananch die spezial Tasten, die dabei gedrückt werden können.
         * @param other der ander Input
         * @return true, wenn es kleiner als der andere ist. False, wenn sie gleich oder der andere kleiner ist.
         */
        bool keyEventSmallerThen(const Input &other) const;

        /**
         * Prüft, ob zwei MouseButton Inputs gleich sind.
         * Sie sind gleich, wenn bei beiden Inputs der gleiche Button gedrückt worden ist.
         * @param other der andere Input
         * @return true, wenn bei Mousebutton Inputs gleich sind. false, wenn nicht
         */
        bool mouseButtonEventEquals(const Input &other) const;

        /**
         * Gibt die natürliche Ordnung für zwei MouseButtonEvents wieder.
         * @param other der ander Input
         * @return true, wenn es kleiner als der andere ist. False, wenn sie gleich oder der andere kleiner ist.
         */
        bool mouseButtonEventSmallerThen(const Input &other) const;

        /**
         * Prüft, ob zwei JoystickButton Inputs gleich sind.
         * Sie sind gleich, wenn bei beiden Inputs derselbe Button vom selben Controller gedruckt wurde.
         * @param other der andere Input
         * @return true, wenn bei JoystickButton Inputs gleich sind. False, wenn nicht
         */
        bool joystickButtonEventEquals(const Input &other) const;

        /**
         * Gibt die natürliche Ordnung für zwei JoystickButtonEvents wieder.
         * @param other der andere Input
         * @return true, wenn es kleiner als der andere ist. False, wenn sie gleich oder der andere kleiner ist.
         */
        bool joystickButtonEventSmallerThen(const Input &other) const;

        /**
         * Überprüft, ob zwei Joysticks gleich sind, bei einem JoystickConnected/Disconnect Input.
         * @param other der andere Joystick Input
         * @return true, wenn bei den Joysticks bei den beiden Inputs dasselbe ist. False wenn nicht.
         */
        bool joystickConnectedEquals(const Input &other) const;

        /**
         * Gibt die natürliche Ordnung für zwei JoystickConnected/Disconnected Inputs wieder.
         * @param other der andere Input
         * @return true, wenn es kleiner als der andere ist. False, wenn sie gleich oder der andere kleiner ist.
         */
        bool joystickConnectedSmallerThen(const Input &other) const;

        /**
         * Überprüft, bei einem JoystickMoved Input, ob dieselbe Achse beim selben Joystick geändert wurde.
         * @param other der andere Joystick Input
         * @return true, wenn bei beiden Inputs dieselbe Achse vom selben Joystick geändert wurde. False, wenn nicht.
         */
        bool joystickMovedEquals(const Input &other) const;

        /**
         * Gibt die natürliche Ordnung für zwei JoystickMovedEvents wieder.
         * @param other der andere Input
         * @return true, wenn es kleiner als der andere ist. False, wenn sie gleich oder der andere kleiner ist.
         */
        bool joystickMovedSmallerThen(const Input &other) const;

        /**
         * Kopiert die Event Information in den Input
         * @param event
         */
        void copyEvent(const sf::Event &event);
    };
}
