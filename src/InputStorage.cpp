#include "InputStorage.h"
#include "MyTime.h"

void myGE::InputStorage::registerHoldInput(const Input& input) {
  holdInput[input] = sf::Clock{};
}