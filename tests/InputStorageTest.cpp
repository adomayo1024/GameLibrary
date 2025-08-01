#include <gtest/gtest.h>
#include "InputStorage.h"
#include "TypBenenungen.h"


namespace myGE {
    class InputStorageTest: public ::testing::Test {

        protected:
            void TearDown() override {
                InputStorage::removedAllPressedInputs();
            }

            void doInputs(int i) {
                Input input{
                            Input::ParameterInputKonstruktor{
                                .type = sf::Event::EventType::KeyPressed,
                                .keyEvent = sf::Event::KeyEvent{
                                    .code = sf::Keyboard::A
                                }
                            }
                        };
                for(int j = 0; j < i; j++) {
                    InputStorage::registerInput(input);
                }

            }
    };

    /**
     * Testet, ob beim Initialisieren kein einziger Input registriert ist.
     */
    TEST_F(InputStorageTest, initialize) {
        EXPECT_FALSE(InputStorage::areAnyPressedInputPressed());
        EXPECT_THROW({InputStorage::getLastInput();}, std::runtime_error);
        EXPECT_THROW({InputStorage::getLastNInputs(1);}, std::runtime_error);

    }

    /**
     * Testet, registerInput mit einem simplen Input, gainedFocus.
     */
    TEST_F(InputStorageTest, registerInput_SimpleInput) {
        Input input{Input::ParameterInputKonstruktor{.type = EventType::GainedFocus}};
        InputStorage::registerInput(input);
        EXPECT_FALSE(InputStorage::areAnyPressedInputPressed());
        EXPECT_EQ(std::get<1>(InputStorage::getLastInput()), input);
        EXPECT_TRUE(InputStorage::getPressedInputs().empty());
    }

    /**
     * Testet, registerInput mit einem DataInput, MouseMoved.
     */
    TEST_F(InputStorageTest, registerInput_DataInput) {
        Input input{
                    Input::ParameterInputKonstruktor{
                        .type = EventType::MouseMoved,
                        .mMEvent = sf::Event::MouseMoveEvent{10, 10}
                    }
                };
        InputStorage::registerInput(input);
        EXPECT_EQ(std::get<1>(InputStorage::getLastInput()), input);
        EXPECT_TRUE(InputStorage::getPressedInputs().empty());
    }

    /**
     * Testet, registerInput mit einem KeyInput, KeyPressed.
     */
    TEST_F(InputStorageTest, registerInput_KeyInput) {
        Input input{
                    Input::ParameterInputKonstruktor{
                        .type = EventType::KeyPressed,
                        .keyEvent = sf::Event::KeyEvent{.code = Key::A}
                    }
                };
        InputStorage::registerInput(input);
        EXPECT_EQ(std::get<1>(InputStorage::getLastInput()), input);
    }


    TEST_F(InputStorageTest, registerInput_WithVariouseInputs) {
        Input input1{
                    Input::ParameterInputKonstruktor{
                        .type = EventType::Closed
                    }
                };
        Input input2{
                    Input::ParameterInputKonstruktor{
                        .type = EventType::MouseMoved,
                        .mMEvent = sf::Event::MouseMoveEvent{12, 23}
                    }
                };
        Input input3{
                    Input::ParameterInputKonstruktor{
                        .type = EventType::KeyPressed,
                        .keyEvent = sf::Event::KeyEvent{
                            .code = Key::D
                        }
                    }
                };
        Input input4{
                    Input::ParameterInputKonstruktor{
                        .type = EventType::KeyReleased,
                        .keyEvent = sf::Event::KeyEvent{
                            .code = Key::D
                        }
                    }
                };
        InputStorage::registerInput(input1);
        InputStorage::registerInput(input2);
        InputStorage::registerInput(input3);
        EXPECT_TRUE(InputStorage::areAnyPressedInputPressed());
        InputStorage::registerInput(input4);
        EXPECT_FALSE(InputStorage::areAnyPressedInputPressed());
        EXPECT_EQ(std::get<1>(InputStorage::getLastInput()), input4);
        std::vector<registeredInputs> inputs = InputStorage::getLastNInputs(4);
        EXPECT_EQ(std::get<1>(inputs[3]), input1);
        EXPECT_EQ(std::get<1>(inputs[2]), input2);
        EXPECT_EQ(std::get<1>(inputs[1]), input3);
        EXPECT_EQ(std::get<1>(inputs[0]), input4);

    }

    /**
     * Testet, ob getLastInput bei nur einem registrierten Input diesen Input zurückgibt.
     * Und das auch mehrmals hintereinander.
     */
    TEST_F(InputStorageTest, lastInput_WithOneInput) {
        doInputs(1);
        EXPECT_TRUE(InputStorage::areAnyPressedInputPressed());
        EXPECT_EQ(std::get<1>(InputStorage::getLastInput()).key.code, Key::A);
        EXPECT_EQ(std::get<1>(InputStorage::getLastInput()).key.code, Key::A);
    }

    /**
     * Testet, ob getLastNInputs bei nur einem registrierten Input nur diesen zurückgibt.
     * Und das auch mehrmals hintereinander.
     */
    TEST_F(InputStorageTest, lastNInputs_WithOneInput) {
        doInputs(1);
        EXPECT_TRUE(InputStorage::areAnyPressedInputPressed());
        std::vector<registeredInputs> inputs = InputStorage::getLastNInputs(1);
        EXPECT_EQ(std::get<1>(inputs[0]).key.code, Key::A);
        inputs = InputStorage::getLastNInputs(1);
        EXPECT_EQ(std::get<1>(inputs[0]).key.code, Key::A);
    }


}
