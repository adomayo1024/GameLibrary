# pragma once
#include <functional>
#include <SFML/Window/Event.hpp>

#include "Input.h"

/**
 * Datei die lange Typen in einfache namen definiert
 */
using inputHandlerFunktion = std::function<void(const myGE::Input &, float)>;
using Key = sf::Keyboard::Key;
using EventType = sf::Event::EventType;