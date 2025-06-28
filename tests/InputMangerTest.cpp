#include <gtest/gtest.h>
#include "Mocks/InputableMock.h"
#include "InputManager.h"
#include <SFML/Window/Event.hpp>

#include "InputStorage.h"
#include "Storage.h"

namespace myGE {
    class InputManagerTest : public ::testing::Test {
    protected:
        void TearDown() override {
            InputStorage::removedAllPressedInputs();
        }
    };

    /**
     * Testet, das Initialisieren eines Inputmanagers ohne vorherige Anmeldungen.
     */
    TEST_F(InputManagerTest, InitializeWithNothing) {
        InputManager inputManager{};
        EXPECT_TRUE(inputManager.listners.empty());
    }

    /**
     * Testet, ob beim Initialisieren eines Inputmanagers mit schon mitgelieferten Anmeldungen, diese auch richtig angemeldet werden.
     */
    TEST_F(InputManagerTest, InitializeWithElements) {
        InputableMock mock{};
        std::vector<std::tuple<Input, inputHandlerFunktion> > inputHandlers = mock.giveEventListner();
        InputManager inputManager{inputHandlers};
        EXPECT_FALSE(inputManager.listners.empty());
        EXPECT_EQ(1, inputManager.listners.size());
        EXPECT_FALSE(inputManager.pressedListners.empty());
        EXPECT_EQ(1, inputManager.pressedListners.size());
    }

    /**
     * Testet, ob bei einem nicht Key event auch alle Objekte benachrichtigt werden, die sich dafür angemeldet haben
     * und deren Funktionen aufgerufen werden, mit denen sie sich angemeldet haben.
     */
    TEST_F(InputManagerTest, ManageNonKeyInput) {
        InputableMock mock{};
        std::vector<std::tuple<Input, inputHandlerFunktion> > inputHandlers = mock.giveEventListner();
        InputManager inputManager{inputHandlers};
        EXPECT_CALL(mock, mockNotKey(testing::_, testing::_))
                .Times(1);
        Input input{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::MouseMoved,
                .mMEvent = sf::Event::MouseMoveEvent{
                }
            }
        };
        inputManager.manage(input, 12);
    }

    /**
     * Testet, ob bei einem Key Event die Objekte noch nicht über das Event benachrichtigt werden.
     * Aber der Key als gedrückt registriert wird, im Storage.
     */
    TEST_F(InputManagerTest, ManageKeyInput) {
        InputableMock mock{};
        std::vector<std::tuple<Input, inputHandlerFunktion> > inputHandlers = mock.giveEventListner();
        InputManager inputManager{inputHandlers};
        EXPECT_CALL(mock, mockKey(testing::_, testing::_))
                .Times(0);
        Input input{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::KeyPressed,
                .keyEvent = sf::Event::KeyEvent{
                    .code = sf::Keyboard::Key::Right,
                    .scancode = sf::Keyboard::Scan::Right
                }
            }
        };
        inputManager.manage(input, 12);
        EXPECT_TRUE(InputStorage::isPressedInputPressed(input));
    }

    /**
     * Testet, ob auch alle Objekte, die sich für ein Key Event angemeldet haben, auch benachrichtigt werden und die
     * Funktionen aufgerufen werden, mit der sie sich angemeldet haben.
     */
    TEST_F(InputManagerTest, handleStillPressedKeys) {
        InputableMock mock{};
        std::vector<std::tuple<Input, inputHandlerFunktion> > inputHandlers = mock.giveEventListner();
        InputManager inputManager{inputHandlers};
        Input input{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::KeyPressed,
                .keyEvent = sf::Event::KeyEvent{
                    .code = sf::Keyboard::Key::Right,
                    .scancode = sf::Keyboard::Scan::Right
                }
            }
        };
        inputManager.manage(input, 12);
        EXPECT_CALL(mock, mockKey(testing::_, testing::_))
                .Times(1);
        inputManager.handleStillPressedInput(12);
        EXPECT_TRUE(InputStorage::isPressedInputPressed(input));
    }

    /**
     * Testet, ob bei einem Event die Elemente, die sich nicht für das Event angemeldet haben, auch nicht benachrichtigt werden.
     */
    TEST_F(InputManagerTest, handleStillPressedKeysElementsNotCall) {
        InputableMock mock{};
        std::vector<std::tuple<Input, inputHandlerFunktion> > inputHandlers = mock.giveEventListner();
        InputManager inputManager{inputHandlers};
        EXPECT_CALL(mock, mockKey(testing::_, testing::_))
                .Times(0);
        EXPECT_CALL(mock, mockNotKey(testing::_, testing::_))
                .Times(0);
        Input input{
            myGE::Input{
                myGE::Input::ParameterEventTypeInputKonstruktor{
                    .type = sf::Event::EventType::MouseLeft}
            }
        };
        inputManager.manage(input, 12);
        inputManager.handleStillPressedInput(12);
    }

    /**
     * Testet, wenn sich Elemente für einen Input anmelden, diese auch bei dem Input benachrichtigt werden.
     */
    TEST_F(InputManagerTest, setListner) {
        InputableMock mock{};
        std::vector<std::tuple<Input, inputHandlerFunktion> > inputHandlers = mock.giveEventListner();
        InputManager inputManager{};
        inputManager.setListner(inputHandlers.at(0));
        Input input{
            myGE::Input::ParameterEventTypeInputKonstruktor{
                .type = sf::Event::EventType::KeyPressed,
                .keyEvent = sf::Event::KeyEvent{
                    .code = sf::Keyboard::Key::Right,
                    .scancode = sf::Keyboard::Scan::Right
                }
            }
        };
        EXPECT_CALL(mock, mockKey(testing::_, testing::_))
                .Times(1);
        inputManager.manage(input, 12);
        inputManager.handleStillPressedInput(12);
        EXPECT_TRUE(myGE::InputStorage::isPressedInputPressed(input));
    }

    /**
     * Testet, wenn sich mehrere Elemente für einen gleichen Input anmelden auch alle Element benachrichtigt werden
     */
    TEST_F(InputManagerTest, setListnersDiffrentElements) {
        InputableMock mock{};
        InputableMock mock2{};
        std::vector<std::tuple<Input, inputHandlerFunktion> > inputHandlers = mock.giveEventListner();
        std::vector<std::tuple<Input, inputHandlerFunktion> > inputHandlers2 = mock2.giveEventListner();
        InputManager inputManager{inputHandlers};
        inputManager.setListners(inputHandlers2);
        EXPECT_CALL(mock, mockNotKey(testing::_, testing::_))
                .Times(1);
        EXPECT_CALL(mock2, mockNotKey(testing::_, testing::_))
                .Times(1);
        EXPECT_CALL(mock, mockKey(testing::_, testing::_))
                .Times(0);
        EXPECT_CALL(mock2, mockKey(testing::_, testing::_))
                .Times(0);
        Input input{
            myGE::Input{
                myGE::Input::ParameterEventTypeInputKonstruktor{
                    .type = sf::Event::EventType::MouseMoved,
                    .mMEvent=sf::Event::MouseMoveEvent{}
                }
            }
        };
        inputManager.manage(input, 12);
        inputManager.handleStillPressedInput(12);
    }
}
