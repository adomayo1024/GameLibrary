#include "Input.h"


bool myGE::Input::operator==(const Input& other) {
      bool result = false;

      switch(other.type) {
        case sf::Event::KeyPressed:
          result = keyEventEquals(other);
          break;
        case sf::Event::KeyReleased:
          result = keyEventEquals(other);
          break;
        case sf::Event::MouseButtonPressed:
          result = mouseButtonEventEquals(other);
          break;
        case sf::Event::MouseButtonReleased:
          result = mouseButtonEventEquals(other);
          break;
        case sf::Event::JoystickButtonPressed:
          result = joystickButtonEventEquals(other);
          break;
        case sf::Event::JoystickButtonReleased:
          result = joystickButtonEventEquals(other);
          break;
        case sf::Event::JoystickConnected:
          result = joystickEquals(other);
          break;
        case sf::Event::JoystickDisconnected:
          result = joystickEquals(other);
          break;
        case sf::Event::JoystickMoved:
          result = joystickEquals(other);
          break;
        default:
          result = true;
          break;
       }
      return result;
  }

bool myGE::Input::keyEventEquals(const myGE::Input& other) {

  bool result = false;

  if(this->key.code == other.key.code &&  // es wird die selbe Taste gedrückt
      this->key.alt == other.key.alt &&   // es wird bei beiden die alt taste gedrückt bzw nicht
      this->key.control == other.key.control && // es wird bei beiden die ctr taste gedrückt bzw nicht
      this->key.shift == other.key.shift && // es wird bei beiden die shift taste gedrückt bzw nicht
      this->key.system == other.key.system) { // es wird bei beiden die system taste gedrückt bzw nicht
    result = true;
      }
  return result;
}

bool myGE::Input::mouseButtonEventEquals(const myGE::Input& other) {
  bool result = false;

  if(this->mouseButton.button == other.mouseButton.button) { // es werden die selben Maustasten gedrückt
    result = true;
  }

  return result;
}

bool myGE::Input::joystickButtonEventEquals(const myGE::Input& other) {
  bool result = false;

  if(this->joystickButton.button == other.joystickButton.button && // es wird der selbe Button gedrückt
      this->joystickButton.joystickId == other.joystickButton.joystickId) { // der Button wird vom selben Controller gedrückt

        result = true;
      }

  return result;
}

bool myGE::Input::joystickEquals(const myGE::Input& other) {
  bool result = false;

  if(this->joystickConnect.joystickId == other.joystickConnect.joystickId) {
    result = true;
  }

  return result;
}