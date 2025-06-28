#pragma once
#include "Input.h"
#include <vector>
#include <tuple>
#include <array>


static constexpr int amountOnSavedInputs = 1024;

namespace myGE {
    /**
    * Der Input speichert alle möglichen Sachen über die derzeitigen Inputs.
    * Wie welche Key werden zur Zeit gedrückt, was waren die letzten Inputs.
    */
    class InputStorage {
    public:

        /**
         * Registriert einkommende Inputs und speichert diese.
         * Wenn 1024 Inputs, die gespeichert werden, erreicht wurden, werden die ersten gelöscht.
         */
        static void registerInput(Input &input);

        /**
         * Gibt eine Liste mit allen derzeitigen PressedInputs.
         * @return liste aller pressedInputs
         */
        static std::vector<Input> getPressedInputs();

        /**
         * Überprüft, ob ein PressedInput gerade gedrückt wird.
         * @param input der PressedInput, der überprüft werden soll
         * @return true, falls er gedrückt wird. False, wenn nicht.
         */
        static bool isPressedInputPressed(Input &input);

        /**
         * Guckt, ob gerade überhaupt irgendein PressedInput gedrückt wird.
         * @return true, wenn mindestens ein PressedInput gedrückt wird. False, wenn gar keiner gedrückt wird.
         */
        static bool areAnyPressedInputPressed();

        /**
         * Entfernt alle PressedInputs, sodass sie nicht mehr als gedrückt gespeichert werden.
         */
        static void removedAllPressedInputs();

    private:
        /**
           * Registriert einen PressedInput.
           */
        static void registerPressedInput(const Input &input);

        /**
         * Meldet einen PressedInput ab.
         * Es wurde der zugehörige ReleasedInput erhalten.
         */
        static void unregisterPressedInput(const Input &input);


        /**
         * Speichert, welche PressedInputs passiert sind, und gerade gedrückt werden.
         * Mit einer Stopuhr, die misst, wie lange der Input schon gedrückt wird.
         */
        static std::vector<Input> pressedInputs;

        /**
         * Speichert, die letzten @amountOnSavedInputs mit der Zeit, wann sie passiert sind.
         */
        static std::array<std::tuple<float, Input>, amountOnSavedInputs> lastInputs;

        /**
         * Index des letzten passiert Inputs, in@lastInputs.
         */
        static int i; // TODO tausch es vielleicht gegen eigen Zyklischer Integer klasse aus
    };
}
