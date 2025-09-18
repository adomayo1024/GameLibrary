#include <gtest/gtest.h>
#include "UpdateManager.h"
#include "Mocks/UpdateableMock.h"

namespace myGE {


    TEST(UpdateManagerTest, Initialize) {
        myGE::UpdateManager manager{};
        EXPECT_TRUE(manager.updatables.empty());
    }

    TEST(UpdateManagerTest, setUpdateObj) {
        myGE::UpdateManager manager{};
        std::shared_ptr<UpdateableMock> mock_ptr = std::make_shared<UpdateableMock>();
        std::shared_ptr<Updatable> updateable_ptr = mock_ptr;
        manager.setUpdateObj(updateable_ptr);
        EXPECT_EQ(1, manager.updatables.size());
    }

}