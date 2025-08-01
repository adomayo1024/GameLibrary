#pragma once
#include "Input.h"
#include <vector>
#include <array>

#include "CycleInt.h"


static constexpr int amountOnSavedInputs = 1024;

namespace myGE {


    /**
    * Der Input speichert alle möglichen Sachen über die derzeitigen Inputs.
    * Wie welche Key werden zurzeit gedrückt, was waren die letzten Inputs.
    */
    class InputStorage {
        public:
            /**
             * Registriert einkommende Inputs und speichert diese.
             * Wenn 1024 Inputs, die gespeichert werden, erreicht wurden, werden die ersten wieder gelöscht.
             */
            static void registerInput(Input &input);

            static std::tuple<float, myGE::Input> &getLastInput();

            static std::vector<std::tuple<float, myGE::Input>> getLastNInputs(int n);

            /**
             * Gibt eine Liste mit allen derzeitigen PressedInputs.
             * @return liste aller pressedInputs
             */
            static const std::vector<Input> &getPressedInputs();

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
            static CycleInt i;

            /**
             * Eine Zählvariable, die angibt, wie viele Inputs insgesamt schon registriert worden sind.
             */
            static int howManyRegisterInputs;


            friend class InputStorageTest_initialize_Test;
    };
}
