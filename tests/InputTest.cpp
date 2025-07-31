#include <gtest/gtest.h>

#include "Input.h"
#include "InputStorage.h"
#include "TypBenenungen.h"

namespace myGE {
    class InputTest: public ::testing::Test {
        protected:
            Input closedInput1{
                        myGE::Input::ParameterInputKonstruktor{
                            .type = sf::Event::EventType::Closed
                        }
                    };

            Input closedInput2{
                        myGE::Input::ParameterInputKonstruktor{
                            .type = sf::Event::EventType::Closed
                        }
                    };

            myGE::Input rightKeyPressedInput1{
                        myGE::Input::ParameterInputKonstruktor{
                            .type = sf::Event::EventType::KeyPressed,
                            .keyEvent = sf::Event::KeyEvent{
                                .code = sf::Keyboard::Key::Right,
                                .scancode = sf::Keyboard::Scan::Right
                            }
                        }
                    };

            myGE::Input rightKeyReleasedInput1{
                        myGE::Input::ParameterInputKonstruktor{
                            .type = sf::Event::EventType::KeyReleased,
                            .keyEvent = sf::Event::KeyEvent{
                                .code = Key::Right,
                                .scancode = sf::Keyboard::Scan::Right
                            }
                        }
                    };

            Input rightKeyPressedInput2{
                        myGE::Input::ParameterInputKonstruktor{
                            .type = sf::Event::EventType::KeyPressed,
                            .keyEvent = sf::Event::KeyEvent{
                                .code = Key::Right,
                                .scancode = sf::Keyboard::Scan::Right
                            }
                        }
                    };

            Input leftKeyPressedInput1{
                        myGE::Input::ParameterInputKonstruktor{
                            .type = sf::Event::EventType::KeyPressed,
                            .keyEvent = sf::Event::KeyEvent{
                                .code = Key::Left,
                                .scancode = sf::Keyboard::Scan::Left

                            }
                        }
                    };

            myGE::Input leftMouseButtonPressedInput1{
                        myGE::Input::ParameterInputKonstruktor{
                            .type = sf::Event::EventType::MouseButtonPressed,
                            .mBEvent = sf::Event::MouseButtonEvent{
                                .button = sf::Mouse::Button::Left
                            }
                        }
                    };

            myGE::Input leftMouseButtonReleasedInput1{
                        myGE::Input::ParameterInputKonstruktor{
                            .type = sf::Event::EventType::MouseButtonReleased,
                            .mBEvent = sf::Event::MouseButtonEvent{
                                .button = sf::Mouse::Button::Left
                            }
                        }
                    };

            Input firstJoyStickButtonPressedInput1{
                        myGE::Input::ParameterInputKonstruktor{
                            .type = sf::Event::EventType::JoystickButtonPressed,
                            .jBEvent = sf::Event::JoystickButtonEvent{
                                .joystickId = 1,
                                .button = 1
                            }
                        }
                    };

            Input firstJoyStickButtonReleasedInput1{
                        myGE::Input::ParameterInputKonstruktor{
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

    /**
     * Testet, ob der Konstruktor aufruft, mit der Wrapper Klasse korrekt funktioniert.
     * Die Parameter, die man angibt, werden auch richtig beim Input Objekt gesetzte.
     */
    TEST_F(InputTest, wrapperClassConstructor) {
        Input input{
                    Input::ParameterInputKonstruktor{
                        .type = EventType::KeyPressed,
                        .keyEvent = sf::Event::KeyEvent{
                            .code = Key::Right,
                            .scancode = sf::Keyboard::Scan::Right
                        }
                    }
                };
        EXPECT_EQ(input.type, EventType::KeyPressed);
        EXPECT_EQ(input.key.code, Key::Right);
        EXPECT_EQ(input.key.scancode, sf::Keyboard::Scan::Right);
    }

    /**
     * Testet, wenn zwei Events beim ParameterInputKonstruktor gesetzt werden, dann wird nur das Event auch übertragen, welches zu dem Typ passt.
     * Bei diesem Test sollte nur das KeyEvent gesetzt werden beim Input.
     */
    TEST_F(InputTest, wrapperClassConstructorMoreEventsDefinied) {
        Input input{
                    Input::ParameterInputKonstruktor{
                        .type = EventType::KeyPressed,
                        .keyEvent = sf::Event::KeyEvent{
                            .code = Key::Right,
                            .scancode = sf::Keyboard::Scan::Right
                        },
                        .mBEvent = sf::Event::MouseButtonEvent{
                            .button = sf::Mouse::Left
                        }
                    }
                };
        EXPECT_EQ(input.key.code, Key::Right);
        EXPECT_NE(input.mouseButton.button, sf::Mouse::Left);
    }

    TEST_F(InputTest, wrapperClassConstructorNoTypeDeclared) {
        EXPECT_THROW({Input input{
                     Input::ParameterInputKonstruktor{}
                     };}, std::runtime_error);
    }

    /**
     * Testet, den "kleiner als" Operator, ob bei zwei gleichen Inputs immer false herauskommt.
     * Mit zwei sehr einfachen Inputs, die keine zusätzlichen Daten haben.
     */
    TEST_F(InputTest, smallerThenOperatorForEasySameInput) {
        EXPECT_FALSE(closedInput1 < closedInput2);
        EXPECT_FALSE(closedInput2 < closedInput1);
    }



    /**
     * Testet, ob der "kleiner als" Operator richtig funktioniert, bei zwei unterschiedlichen Inputs.
     */
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

    /**
     * Testet, ob der Gleichheitsoperator true liefert bei demselben Objekt.
     */
    TEST_F(InputTest, equalsTheSame) {
        EXPECT_TRUE(rightKeyPressedInput1 == rightKeyPressedInput1);
    }

    /**
     * Testet, ob der Gleichheitsoperator true liefert, bei zwei gleichen Objekten.
     */
    TEST_F(InputTest, equalsSameType) {
        EXPECT_TRUE(rightKeyPressedInput1 == rightKeyPressedInput2);
    }

    /**
     * Testet, ob der Gleichheitsoperator false liefert, bei zwei Inputs, desselben Typs, aber unterschiedlichen Daten.
     */
    TEST_F(InputTest, notEqualsSameType) {
        EXPECT_FALSE(rightKeyPressedInput1 == leftKeyPressedInput1);
    }

    /**
     * Testet, ob der Gleichheitsoperator false liefert, bei zwei Inputs von unterschiedlichem Typ.
     */
    TEST_F(InputTest, noEqualsDiffrentType) {
        EXPECT_FALSE(rightKeyPressedInput1 == closedInput1);
    }


}
