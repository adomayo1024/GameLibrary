#pragma once

#include <memory>
#include <vector>
#include "Updatable.h"

namespace myGE {

class UpdateManager {

public:
    UpdateManager();

    void update();

    void setUpdateObj(std::shared_ptr<myGE::Updatable>&);

private:
    std::vector<std::shared_ptr<myGE::Updatable>> updatables;

    friend class UpdateManagerTest_Initialize_Test;
    friend class UpdateManagerTest_setUpdateObj_Test;
};
}