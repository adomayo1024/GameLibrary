#include "Input.h"

#include <iostream>
#include <memory>

#include "TypBenenungen.h"


myGE::Input::Input(ParameterInputKonstruktor params) : Event() {
  this->type = params.type;
  this->key.code = params.key;
  this->key.alt = params.alt;
  this->key.control = params.ctr;
  this->key.shift = params.shift;
  this->key.system = params.system;
  this->mouseButton.button = params.mouseButton;
  this->joystickButton.button = params.joyStickButton;
  this->joystickButton.joystickId = params.joyStickId;
  this->joystickMove.joystickId = params.joyStickId;
  this->joystickConnect.joystickId = params.joyStickId;
}

myGE::Input::Input(sf::Event event) : Event() {
  copyEvent(event);
}

myGE::Input::Input(Input &input) {
  this->mouseButton = input.mouseButton;
  this->joystickButton = input.joystickButton;
  this->joystickConnect = input.joystickConnect;
  this->joystickMove = input.joystickMove;
  this->mouseMove = input.mouseMove;
  this->mouseWheel = input.mouseWheel;
  this->mouseWheelScroll = input.mouseWheelScroll;
  this->sensor = input.sensor;
  this->size = input.size;
  this->text = input.text;
  this->touch = input.touch;
  this->type = input.type;
  this->key = input.key;
}

bool myGE::Input::operator==(const Input& other) const {
      bool result = false;
      if (type == other.type) {

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
              result = joystickConnectedEquals(other);
              break;
            case sf::Event::JoystickDisconnected:
              result = joystickConnectedEquals(other);
              break;
            case sf::Event::JoystickMoved:
              result = joystickMovedEquals(other);
              break;
            default:
              result = true;
              break;
        }
      }
      return result;
  }

bool myGE::Input::operator<(const Input &other) const {

  bool result = false;

  if (type == other.type) {

    switch(other.type) {
      case sf::Event::KeyPressed:
        result = keyEventSmallerThen(other);
        break;
      case sf::Event::KeyReleased:
        result = keyEventSmallerThen(other);
        break;
      case sf::Event::MouseButtonPressed:
        result = mouseButtonEventSmallerThen(other);
        break;
      case sf::Event::MouseButtonReleased:
        result = mouseButtonEventSmallerThen(other);
        break;
      case sf::Event::JoystickButtonPressed:
        result = joystickButtonEventSmallerThen(other);
        break;
      case sf::Event::JoystickButtonReleased:
        result = joystickButtonEventSmallerThen(other);
        break;
      case sf::Event::JoystickConnected:
        result = joystickConnectedSmallerThen(other);
        break;
      case sf::Event::JoystickDisconnected:
        result = joystickConnectedSmallerThen(other);
        break;
      case sf::Event::JoystickMoved:
        result = joystickMovedSmallerThen(other);
        break;
      default:
        result = type < other.type;
        break;
    }
  }
  else {
    result = type < other.type;
  }
  return result;
}

myGE::Input & myGE::Input::operator=(const sf::Event event) {
  copyEvent(event);
  return *this;
}

bool myGE::Input::keyEventEquals(const myGE::Input& other) const {

  bool result = false;

  if(this->key.code == other.key.code &&  // es wird dieselbe Taste gedrückt
      this->key.alt == other.key.alt &&   // es wird bei beiden die alt Taste gedrückt bzw nicht
      this->key.control == other.key.control && // es wird bei beiden die ctr taste gedrückt bzw nicht
      this->key.shift == other.key.shift && // es wird bei beiden die shift taste gedrückt bzw nicht
      this->key.system == other.key.system) { // es wird bei beiden die system taste gedrückt bzw nicht
    result = true;
      }
  return result;
}

bool myGE::Input::keyEventSmallerThen(const Input &other) const {
  bool result = false;
  if (key.code != other.key.code) {
    result = key.code < other.key.code;
  }
  else if (key.alt != other.key.alt) {
    result = key.alt < other.key.alt;
  }
  else if (key.control != other.key.control) {
    result = key.control < other.key.control;
  }
  else if (key.shift != other.key.shift) {
    result = key.shift < other.key.shift;
  }
  else if (key.system != other.key.system) {
    result = key.system < other.key.system;
  }
  return result;
}

bool myGE::Input::mouseButtonEventEquals(const myGE::Input& other) const {
  bool result = false;

  if(this->mouseButton.button == other.mouseButton.button) { // es werden dieselben Maustasten gedrückt
    result = true;
  }

  return result;
}

bool myGE::Input::mouseButtonEventSmallerThen(const Input &other) const {
  bool result = false;
  if (mouseButton.button != other.mouseButton.button) {
    result = mouseButton.button < other.mouseButton.button;
  }
  return result;
}

bool myGE::Input::joystickButtonEventEquals(const myGE::Input& other) const {
  bool result = false;

  if(this->joystickButton.button == other.joystickButton.button && // es wird der selbe Button gedrückt
      this->joystickButton.joystickId == other.joystickButton.joystickId) { // der Button wird vom selben Controller gedrückt

        result = true;
      }

  return result;
}

bool myGE::Input::joystickButtonEventSmallerThen(const Input &other) const {
  bool result = false;

  if (joystickButton.button != other.joystickButton.button) {
    result = joystickButton.button < other.joystickButton.button;
  }
  else if (joystickButton.joystickId != other.joystickButton.joystickId) {
    result = joystickButton.joystickId < other.joystickButton.joystickId;
  }

  return result;
}

bool myGE::Input::joystickConnectedEquals(const myGE::Input& other) const {
  bool result = false;

  if(this->joystickConnect.joystickId == other.joystickConnect.joystickId) {
    result = true;
  }

  return result;
}

bool myGE::Input::joystickConnectedSmallerThen(const Input &other) const {
  bool result = false;

  if (joystickConnect.joystickId != other.joystickConnect.joystickId) {
    result = joystickConnect.joystickId < other.joystickConnect.joystickId;
  }

  return result;
}

bool myGE::Input::joystickMovedEquals(const Input &other) const {
  bool result = false;

  if(this->joystickMove.joystickId == other.joystickMove.joystickId &&
    this->joystickMove.axis == other.joystickMove.axis) {
    result = true;
  }

  return result;
}

bool myGE::Input::joystickMovedSmallerThen(const Input &other) const {
  bool result = false;

  if (joystickMove.joystickId != other.joystickMove.joystickId) {
    result = joystickMove.joystickId < other.joystickMove.joystickId;
  }
  else if (joystickMove.axis != other.joystickMove.axis) {
    result = joystickMove.axis < other.joystickMove.axis;
  }

  return result;
}

void myGE::Input::copyEvent(const sf::Event &event){
  this->mouseButton = event.mouseButton;
  this->joystickButton = event.joystickButton;
  this->joystickConnect = event.joystickConnect;
  this->joystickMove = event.joystickMove;
  this->mouseMove = event.mouseMove;
  this->mouseWheel = event.mouseWheel;
  this->mouseWheelScroll = event.mouseWheelScroll;
  this->sensor = event.sensor;
  this->size = event.size;
  this->text = event.text;
  this->touch = event.touch;
  this->type = event.type;
  this->key = event.key;
}

bool myGE::Input::isItPressedInput(const Input &input) {
  bool result = false;
  if (input.type == sf::Event::EventType::KeyPressed ||
    input.type == sf::Event::EventType::MouseButtonPressed ||
    input.type == sf::Event::EventType::JoystickButtonPressed) {
    result = true;
  }
  return result;
}

bool myGE::Input::isItReleasedInput(const Input &input) {
  bool result = false;
  if (input.type == sf::Event::EventType::KeyReleased||
    input.type == sf::Event::EventType::MouseButtonReleased ||
    input.type == sf::Event::EventType::JoystickButtonReleased) {
    result = true;
    }
  return result;
}

