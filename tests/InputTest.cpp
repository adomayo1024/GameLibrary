#include <gtest/gtest.h>

#include "Input.h"
#include "TypBenenungen.h"

namespace myGE {
    TEST(InpuTest, smallerThenOperatorForEasySameInput) {
        myGE::Input input1{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::Closed
            }
        };
        Input input2{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::Closed
            }
        };
        EXPECT_FALSE(input1 < input2);
        EXPECT_FALSE(input2 < input1);
    }

    TEST(InputTest, smallerThenOperatorForEasyNotSameInput) {
        myGE::Input input1{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::KeyPressed
            }
        };
        Input input2{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::Closed
            }
        };
        EXPECT_FALSE(input1 < input2);
        EXPECT_TRUE(input2 < input1);
    }

    TEST(InputTest, smallerThenOperator) {
        myGE::Input input1{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::KeyPressed,
                .keyEvent = sf::Event::KeyEvent{.code = Key::Right}
            }
        };
        Input input2{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::KeyPressed,
                .keyEvent = sf::Event::KeyEvent{.code = Key::Right}
            }
        };
        EXPECT_FALSE(input1 < input2);
        EXPECT_FALSE(input2 < input1);
    }

    TEST(InputTest, containsInMapForEasyInput) {
        myGE::Input input1{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::Closed
            }
        };
        Input input2{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::Closed
            }
        };
        std::map<Input, int> map{};
        map[input1] = 1;
        EXPECT_TRUE(map.contains(input2));
    }

    TEST(InputTest, euqals) {
        Input input{myGE::Input::ParameterEventTypeInputKonstruktor{
        .type=sf::Event::EventType::KeyPressed,
        .keyEvent=sf::Event::KeyEvent{
        .code=sf::Keyboard::Key::Right,
        .scancode=sf::Keyboard::Scancode::Right}}};
        Input input2{myGE::Input::ParameterEventTypeInputKonstruktor{
            .type=sf::Event::EventType::KeyReleased,
            .keyEvent=sf::Event::KeyEvent{
                .code=sf::Keyboard::Key::Right,
                .scancode=sf::Keyboard::Scancode::Right}}};
        Input input3{input2};
        input3.type = input.type;
        EXPECT_TRUE(input == input3);
    }
}
