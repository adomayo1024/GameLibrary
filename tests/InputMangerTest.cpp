#include <gtest/gtest.h>

#include "InputManager.h"

namespace myGE {
    TEST(InputManagerTest, Initialize) {
        InputManager inputManager{};
        EXPECT_TRUE(inputManager.listnerMap.empty());
        EXPECT_TRUE(inputManager.keyMap.empty());
    }
}
