#include <gtest/gtest.h>
#include "Mocks/InputableMock.h"
#include "InputManager.h"
#include <SFML/Window/Event.hpp>

#include "Storage.h"

namespace myGE {
    TEST(InputManagerTest, InitializeWithNothing) {
        InputManager inputManager{};
        EXPECT_TRUE(inputManager.listnerMap.empty());
        EXPECT_TRUE(inputManager.keyMap.empty());
    }

    TEST(InputManagerTest, InitializeWithElements) {
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
    TEST(InputManagerTest, ManageNonKeyInput) {
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
    TEST(InputManager, ManageKeyInput) {
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
    TEST(InputManager, handleStillPressedKeys) {
        InputableMock mock{};
        std::vector<std::tuple<EventType, Key, inputHandlerFunktion>> inputHandlers =
            mock.giveEventListner();
        InputManager inputManager{inputHandlers};
        EXPECT_CALL(mock, mockKey(testing::_, testing::_))
        .Times(1);
        sf::Event event = sf::Event{sf::Event::KeyPressed};
        event.key.code = Key::Right;
        inputManager.manage(event, 12);
        EXPECT_TRUE(Storage::containsKey(Key::Right));
        inputManager.handleStillPressedKeys(12);
    }
}
