#pragma once
#include "Input.h"
#include <SFML/System/Clock.hpp>
#include <vector>
#include <map>
#include <tuple>

namespace myGE {
/**
* Der Input Speichert alle möglichen Sachen über die derzeitigen Inputs.
* Wie welche Key werden zur Zeit gedrückt, was waren die letzten Inputs.
*/
class InputStorage {

public:
    InputStorage();

    /**
     * Regestriert einkommende Input und speichert diese.
     * Wenn 1024 Inputs die gespeichert werden erreicht wurden, werden die ersten gelöscht.
     */
    static void registerInput(Input& input);

private:

    /**
       * Regestriert einen HoldInput als das er gedrückt wird, bzw. gehalten wird.
       */
    static void registerHoldInput(const Input& input);

    /**
     * Meldet einen HoldInput ab, er wird nicht mehr gedrückt, bzw. gehlaten.
     */
    static void unregestierHoldInput(Input& input);


  static std::map<Input, sf::Clock> holdInput;
  static std::tuple<int, Input> lastInputs[1024];
};
}