# pragma once
#include <functional>
#include <SFML/Window/Event.hpp>

using inputHandlerFunktion = std::function<void(const sf::Event &, float)>;
using Key = sf::Keyboard::Key;
using EventType = sf::Event::EventType;