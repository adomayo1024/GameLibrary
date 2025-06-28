#include <gtest/gtest.h>

#include "Input.h"
#include "InputStorage.h"
#include "TypBenenungen.h"

namespace myGE {
    class InputTest : public ::testing::Test {
    protected:
        Input closedInput1{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::Closed
            }
        };

        Input closedInput2{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::Closed
            }
        };

        myGE::Input rightKeyPressedInput1{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::KeyPressed,
                .keyEvent = sf::Event::KeyEvent{
                    .code = sf::Keyboard::Key::Right,
                    .scancode = sf::Keyboard::Scan::Right
                }
            }
        };

        myGE::Input rightKeyReleasedInput1{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::KeyReleased,
                .keyEvent = sf::Event::KeyEvent{
                    .code = Key::Right,
                    .scancode = sf::Keyboard::Scan::Right
                }
            }
        };

        Input rightKeyPressedInput2{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::KeyPressed,
                .keyEvent = sf::Event::KeyEvent{
                    .code = Key::Right,
                    .scancode = sf::Keyboard::Scan::Right
                }
            }
        };

        myGE::Input leftMouseButtonPressedInput1{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::MouseButtonPressed,
                .mBEvent = sf::Event::MouseButtonEvent{
                    .button = sf::Mouse::Button::Left
                }
            }
        };

        myGE::Input leftMouseButtonReleasedInput1{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::MouseButtonReleased,
                .mBEvent = sf::Event::MouseButtonEvent{
                    .button = sf::Mouse::Button::Left
                }
            }
        };

        Input firstJoyStickButtonPressedInput1{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::JoystickButtonPressed,
                .jBEvent = sf::Event::JoystickButtonEvent{
                    .joystickId = 1,
                    .button = 1
                }
            }
        };

        Input firstJoyStickButtonReleasedInput1{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::JoystickButtonReleased,
                .jBEvent = sf::Event::JoystickButtonEvent{
                    .joystickId = 1,
                    .button = 1
                }
            }
        };

        void TearDown() override {
            InputStorage::removedAllPressedInputs();
        }
    };

    TEST_F(InputTest, smallerThenOperatorForEasySameInput) {
        EXPECT_FALSE(closedInput1 < closedInput2);
        EXPECT_FALSE(closedInput2 < closedInput1);
    }

    TEST_F(InputTest, smallerThenOperatorForEasyNotSameInput) {
        EXPECT_FALSE(rightKeyPressedInput1 < closedInput1);
        EXPECT_TRUE(closedInput1 < rightKeyPressedInput1);
    }

    TEST_F(InputTest, smallerThenOperator) {
        EXPECT_FALSE(rightKeyPressedInput1 < rightKeyPressedInput2);
        EXPECT_FALSE(rightKeyPressedInput2 < rightKeyPressedInput1);
    }

    TEST_F(InputTest, containsInMapForEasyInput) {
        std::map<Input, int> map{};
        map[closedInput1] = 1;
        EXPECT_TRUE(map.contains(closedInput2));
    }

    /**
     * Testet, ob ein Pressed- bzw. ReleasedInput zu seinem komplimentierten Input gleich ist, wenn man den jeweiligen
     * Typen auf den jeweils anderen Typen ändert, aber die restlichen relevanten Werte unberührt lässt.
     */
    TEST_F(InputTest, euqals) {
        Input rightKeyReleasedTempInput{rightKeyReleasedInput1};
        rightKeyReleasedTempInput.type = rightKeyPressedInput1.type;
        EXPECT_TRUE(rightKeyPressedInput1 == rightKeyReleasedTempInput);

        Input leftMouseButtonReleasedTempInput{leftMouseButtonReleasedInput1};
        leftMouseButtonReleasedTempInput.type = leftMouseButtonPressedInput1.type;
        EXPECT_TRUE(leftMouseButtonPressedInput1 == leftMouseButtonReleasedTempInput);

        Input firstJoyStickButtonReleasedTempInput{firstJoyStickButtonReleasedInput1};
        firstJoyStickButtonReleasedTempInput.type = firstJoyStickButtonPressedInput1.type;
        EXPECT_TRUE(firstJoyStickButtonPressedInput1 == firstJoyStickButtonReleasedTempInput);
    }
}
