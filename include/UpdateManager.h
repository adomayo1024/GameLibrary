#pragma once

#include <memory>
#include <vector>

#include "Updatable.h"

class UpdateManager {

public:
    UpdateManager();

    void update();

    void setUpdateObj(std::shared_ptr<Updatable>&);

private:
    std::vector<std::shared_ptr<Updatable>> updatables;
};
