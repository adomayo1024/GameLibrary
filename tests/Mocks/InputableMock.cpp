#include "InputableMock.h"


std::vector<std::tuple<myGE::Input, inputHandlerFunktion>> InputableMock::giveEventListner() {
    std::vector<std::tuple<
        myGE::Input,
        inputHandlerFunktion>> liste;


    myGE::Input input1{
                myGE::Input{
                    myGE::Input::ParameterInputKonstruktor{
                        .type = sf::Event::EventType::KeyPressed,
                        .keyEvent = sf::Event::KeyEvent{
                            .code = sf::Keyboard::Key::Right,
                            .scancode = sf::Keyboard::Scan::Right
                        }
                    }
                }
            };

    liste.emplace_back(
        input1,
        [this](const sf::Event &event, float deltaTime) {
            this->mockKey(event, deltaTime);
        });


    myGE::Input input2{
                myGE::Input{
                    myGE::Input::ParameterInputKonstruktor{
                        .type = sf::Event::EventType::MouseMoved,
                        .mMEvent = sf::Event::MouseMoveEvent{}
                    }
                }
            };

    liste.emplace_back(
        input2,
        [this](const sf::Event &event, float deltaTime) {
            this->mockNotKey(event, deltaTime);
        });

    return liste;
}
