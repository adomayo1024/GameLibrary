#include <gtest/gtest.h>
#include "Mocks/InputableMock.h"
#include "InputManager.h"
#include <SFML/Window/Event.hpp>

#include "Storage.h"

namespace myGE {

    class InputManagerTest : public ::testing::Test {
    protected:
    void TearDown() override {
        Storage::removeAllKeys();
    }
};

    /**
     * Testet, das Initialisieren eines Inputmanagers ohne vorherige Anmeldungen.
     */
    TEST_F(InputManagerTest, InitializeWithNothing) {
        InputManager inputManager{};
        EXPECT_TRUE(inputManager.listnerMap.empty());
        EXPECT_TRUE(inputManager.keyMap.empty());
    }

    /**
     * Testet, ob beim Initialisieren eines Inputmanagers mit schon mitgelieferten Anmeldungen, diese auch richtig angemeldet werden.
     */
    TEST_F(InputManagerTest, InitializeWithElements) {
        InputableMock mock{};
        std::vector<std::tuple<EventType, Key, inputHandlerFunktion>> inputHandlers = mock.giveEventListner();
        InputManager inputManager{inputHandlers};
        EXPECT_FALSE(inputManager.listnerMap.empty());
        EXPECT_EQ(1, inputManager.listnerMap.size());
        EXPECT_FALSE(inputManager.keyMap.empty());
        EXPECT_EQ(1, inputManager.keyMap.size());
    }

    /**
     * Testet, ob bei einem nicht Key event auch alle Objekte benachrichtigt werden, die sich dafür angemeldet haben
     * und deren Funktionen aufgerufen werden, mit denen sie sich angemeldet haben.
     */
    TEST_F(InputManagerTest, ManageNonKeyInput) {
        InputableMock mock{};
        std::vector<std::tuple<EventType, Key, inputHandlerFunktion>> inputHandlers = mock.giveEventListner();
        InputManager inputManager{inputHandlers};
        EXPECT_CALL(mock, mockNotKey(testing::_, testing::_))
        .Times(1);
        sf::Event event = sf::Event{EventType::MouseButtonPressed};
        inputManager.manage(event, 12);

    }

    /**
     * Testet, ob bei einem Key Event die Objekte noch nicht über das Event benachrichtigt werden.
     * Aber der Key als gedrückt registriert wird, im Storage.
     */
    TEST_F(InputManagerTest, ManageKeyInput) {
        InputableMock mock{};
        std::vector<std::tuple<EventType, Key, inputHandlerFunktion>> inputHandlers = mock.giveEventListner();
        InputManager inputManager{inputHandlers};
        EXPECT_CALL(mock, mockKey(testing::_, testing::_))
        .Times(0);
        sf::Event event = sf::Event{sf::Event::KeyPressed};
        event.key.code = Key::Right;
        inputManager.manage(event, 12);
        EXPECT_TRUE(Storage::containsKey(Key::Right));
    }

    /**
     * Testet, ob auch alle Objekte, die sich für ein Key Event angemeldet haben, auch benachrichtigt werden und die
     * Funktionen aufgerufen werden, mit der sie sich angemeldet haben.
     */
    TEST_F(InputManagerTest, handleStillPressedKeys) {
        InputableMock mock{};
        std::vector<std::tuple<EventType, Key, inputHandlerFunktion>> inputHandlers =
            mock.giveEventListner();
        InputManager inputManager{inputHandlers};
        sf::Event event = sf::Event{sf::Event::KeyPressed};
        event.key.code = Key::Right;
        inputManager.manage(event, 12);
        EXPECT_CALL(mock, mockKey(testing::_, testing::_))
        .Times(1);
        inputManager.handleStillPressedKeys(12);
        EXPECT_TRUE(Storage::containsKey(Key::Right));
    }

    /**
     * Testet, ob bei einem Event die Elemente, die sich nicht für das Event angemeldet haben, auch nicht benachrichtigt werden.
     */
    TEST_F(InputManagerTest, handleStillPressedKeysElementsNotCall) {
        InputableMock mock{};
        std::vector<std::tuple<EventType, Key, inputHandlerFunktion>> inputHandlers = mock.giveEventListner();
        InputManager inputManager{inputHandlers};
        EXPECT_CALL(mock, mockKey(testing::_, testing::_))
        .Times(0);
        EXPECT_CALL(mock, mockNotKey(testing::_, testing::_))
        .Times(0);
        sf::Event event = sf::Event{sf::Event::MouseMoved};
        inputManager.manage(event, 12);
        inputManager.handleStillPressedKeys(12);
    }

    /**
     * Testet, wenn sich Elemente für einen Input anmelden, diese auch bei dem Input benachrichtigt werden.
     */
    TEST_F(InputManagerTest, setListner) {
        InputableMock mock{};
        std::vector<std::tuple<EventType, Key, inputHandlerFunktion>> inputHandlers = mock.giveEventListner();
        InputManager inputManager{};
        inputManager.setListner(inputHandlers.at(0));
        sf::Event event = sf::Event{sf::Event::KeyPressed};
        event.key.code = Key::Right;
        EXPECT_CALL(mock, mockKey(testing::_, testing::_))
        .Times(1);
        inputManager.manage(event, 12);
        inputManager.handleStillPressedKeys(12);
        EXPECT_TRUE(Storage::containsKey(Key::Right));
    }

    /**
     * Testet, wenn sich mehrere Elemente für einen gleichen Input anmelden auch alle Element benachrichtigt werden
     */
    TEST_F(InputManagerTest, setListnersDiffrentElements) {
        InputableMock mock{};
        InputableMock mock2{};
        std::vector<std::tuple<EventType, Key, inputHandlerFunktion>> inputHandlers = mock.giveEventListner();
        std::vector<std::tuple<EventType, Key, inputHandlerFunktion>> inputHandlers2 = mock2.giveEventListner();
        inputHandlers.emplace_back(inputHandlers2.at(0));
        inputHandlers.emplace_back(inputHandlers2.at(1));
        InputManager inputManager{inputHandlers};
        EXPECT_CALL(mock, mockNotKey(testing::_, testing::_))
        .Times(1);
        EXPECT_CALL(mock2, mockNotKey(testing::_, testing::_))
        .Times(1);
        EXPECT_CALL(mock, mockKey(testing::_, testing::_))
        .Times(0);
        EXPECT_CALL(mock2, mockKey(testing::_, testing::_))
        .Times(0);
        sf::Event event = sf::Event{sf::Event::MouseButtonPressed};
        inputManager.manage(event, 12);
        inputManager.handleStillPressedKeys(12);
    }
}