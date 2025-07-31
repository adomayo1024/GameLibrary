#include <gtest/gtest.h>
#include "InputStorage.h"


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

    TEST_F(InputStorageTest, initialize) {
        EXPECT_FALSE(InputStorage::areAnyPressedInputPressed());
        EXPECT_THROW({InputStorage::getLastInput();}, std::runtime_error);
        EXPECT_THROW({InputStorage::getLastNInputs(1);}, std::runtime_error);

    }

    TEST_F(InputStorageTest, test) {
        doInputs(2);
        EXPECT_TRUE(InputStorage::areAnyPressedInputPressed());
        EXPECT_TRUE(std::get<1>(InputStorage::getLastInput()).key.code == sf::Keyboard::Key::A);
    }

}
