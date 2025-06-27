#include "InputStorage.h"

#include <array>

#include "MyTime.h"


namespace myGE {
  std::vector<Input> InputStorage::pressedInputs{};
  std::array<std::tuple<float, Input>, amountOnSavedInputs> InputStorage::lastInputs{};
  int InputStorage::i = 0;
}

void myGE::InputStorage::registerInput(Input &input) {
  float time = MyTime::getWholeTimeThisSession();
  std::tuple inputTuple{time, input};
  lastInputs[i] = inputTuple;
  i = (i + 1) % (amountOnSavedInputs + 1);

  if (Input::isItPressedInput(input)) {
    registerPressedInput(input);
  }
  else if (Input::isItReleasedInput(input)) {
    unregisterPressedInput(input);
  }

}

std::vector<myGE::Input> myGE::InputStorage::getPressedInputs() {
  return pressedInputs;

}

bool myGE::InputStorage::isPressedInputPressed(Input &input) {
  bool result = false;
  auto it = std::find(pressedInputs.begin(), pressedInputs.end(), input);
  if (it != pressedInputs.end()) {
    result = true;
  }
  return result;
}

bool myGE::InputStorage::areAnyPressedInputPressed() {
  return !pressedInputs.empty();
}

void myGE::InputStorage::registerPressedInput(const Input& input) {
  pressedInputs.emplace_back(input);
}

void myGE::InputStorage::unregisterPressedInput(const Input &input) {


}


