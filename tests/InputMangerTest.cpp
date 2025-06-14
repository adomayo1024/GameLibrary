#include <gtest/gtest.h>
#include "Mocks/InputableMock.h"
#include "InputManager.h"
#include <SFML/Window/Event.hpp>

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

    TEST(InputManagerTest, Manage) {
        InputableMock mock{};
        std::vector<std::tuple<EventType, Key, inputHandlerFunktion>> inputHandlers = mock.giveEventListner();
        InputManager inputManager{inputHandlers};
        EXPECT_CALL(mock, mockKey(testing::_, testing::_))
        .Times(0);
        EXPECT_CALL(mock, mockNotKey(testing::_, testing::_))
        .Times(1);
        sf::Event event = sf::Event{EventType::MouseButtonPressed};
        inputManager.manage(event, 12);
    }
}
