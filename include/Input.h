#pragma once
#include <SFML/Window/Event.hpp>


namespace myGE {
    /**
     * Die Klasse Input repräsentiert Eingaben (wie Tasten- und Mausaktionen) und erweitert die Eigenschaften des SFML Events.
     */
    class Input: public sf::Event {
        public:
            /**
             * Wrapper Struct, um einen spezifischen Input zu konstruieren.
             */
            struct ParameterInputKonstruktor {
                sf::Event::EventType type = sf::Event::EventType::Count;
                sf::Event::JoystickButtonEvent jBEvent = sf::Event::JoystickButtonEvent{};
                sf::Event::JoystickConnectEvent jCEvent = sf::Event::JoystickConnectEvent{};
                sf::Event::JoystickMoveEvent jMEvent = sf::Event::JoystickMoveEvent{};
                sf::Event::KeyEvent keyEvent = sf::Event::KeyEvent{};
                sf::Event::MouseButtonEvent mBEvent = sf::Event::MouseButtonEvent{};
                sf::Event::MouseMoveEvent mMEvent = sf::Event::MouseMoveEvent{};
                sf::Event::MouseWheelEvent mWEvent = sf::Event::MouseWheelEvent{};
                sf::Event::MouseWheelScrollEvent mWSEvent = sf::Event::MouseWheelScrollEvent{};
                sf::Event::SensorEvent sensorEvent = sf::Event::SensorEvent{};
                sf::Event::SizeEvent sizeEvent = sf::Event::SizeEvent{};
                sf::Event::TextEvent textEvent = sf::Event::TextEvent{};
                sf::Event::TouchEvent touchEvent = sf::Event::TouchEvent{};
            };


            Input() = default;

            ~Input() = default;

            /**
             * Konstruktor, um einen Input zu erstellen, und mit eigenen Werten direkt zu versehen.
             * Alle Parameter sind optional, außer dem Typ des Inputs.
             * Man sollte aber das zugehörige Event zum Typen auch angeben.
             * Achtung man sollte immer nur einen Event Parameter bestimmen, weil sonst es zu Problemen führen kann.
             * Beispiel:
             * Wenn der Typ "KeyPressed" ist, sollte man auch keyEvent ein KeyEvent mitgeben, welches dann die Taste definiert.
             * @param params die Wrapper Klasse, die die Werte hält, die der Input haben soll.
             */
            explicit Input(ParameterInputKonstruktor params);

            /**
             * Konstruktor, um einen Input zu erstellen, durch ein SFML event
             * @param event das SFML event welches der Input darstellen soll.
             */
            explicit Input(sf::Event event);

            /**
             * @brief Kopierkonstruktor
             * Es
             * @param input
             */
            Input(Input &input);

            /**
             * @brief Gleichheitsoperator für zwei Inputs.
             * @details Zwei Inputs sind gleich, wenn der Typ gleich ist, zudem, wenn es ein Typ mit extra Daten
             * wie bei KeyPressed ist, müssen diese auch gleich sein.
             * @param other der andere Input mit dem Vergleich stattfindet.
             * @return True, wenn bei gleich sind. False, wenn nicht.
             */
            bool operator==(const Input &other) const;

            /**
             * @brief "Kleiner als" Operator.
             *
             * @details Zuerst wird der Typ verglichen, dort ist die Rangfolge,\n
             * Closed,\n
             * Resized,\n
             * FocusLost,\n
             * FocusGained,\n
             * TextEntered,\n
             * KeyPressed,\n
             * KeyReleased,\n
             * MouseWheelScrolled,\n
             * MouseButtonPressed,\n
             * MouseButtonReleased,\n
             * MouseMoved,\n
             * MouseMovedRaw,\n
             * MouseEntered,\n
             * MouseLeft,\n
             * JoystickButtonPressed,\n
             * JoystickButtonReleased,\n
             * JoystickMoved,\n
             * JoystickConnected,\n
             * JoystickDisconnected,\n
             * TouchBegan,\n
             * TouchMoved,\n
             * TouchEnded,\n
             * SensorChanged.\n
             * Wenn der Typ derselbe ist, werden die zugehörigen privaten Funktionen aufgerufen.
             * Außer es sind Typen, die keine weiteren Daten haben, dann ist es false.
             * @param other der andere Input mit dem Vergleich stattfindet.
             * @return true, wenn dieses Objekt kleiner ist als das andere.
             * False, wenn sie gleich sind oder der andere größer ist.
             */
            bool operator<(const Input &other) const;


            /**
             * @brief Zuweisungsoperator, damit ein  sf::Event ein Input zugewiesen werden kann.
             * @details Bei der Zuweisung werden, alle Werte wie Typ, KeyEvent etc. vom Event dem Input zugewiesen.
             * @param event das Event, welches dem Input zugewiesen wird.
             * @return der neue Input
             */
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
