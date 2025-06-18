#pragma once
#include <SFML/Window/Event.hpp>

namespace myGE {

    class Input : public sf::Event {
      public:
        Input();
        /**
         * Die Equals Methode ob zwei Inputs gleich sind.
         * Es kommt auf den Typ des Events an wie die gleichhet überprüft wird.
         *
         */
        bool operator==(const Input& other);

      private:
        bool keyEventEquals(const Input& other);
        bool mouseButtonEventEquals(const Input& other);
        bool joystickButtonEventEquals(const Input& other);
        bool joystickEquals(const Input& other);



    };

}

