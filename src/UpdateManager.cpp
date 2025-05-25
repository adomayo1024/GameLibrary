#include "../include/UpdateManager.h"

void UpdateManager::update() {
        for (const std::shared_ptr<Updatable>& updatable: updatables) {
                updatable->update();
        }
}

UpdateManager::UpdateManager() : updatables(std::vector<std::shared_ptr<Updatable>>{}) {

}

void UpdateManager::setUpdateObj(std::shared_ptr<Updatable>& updatable) {
        updatables.push_back(updatable);
}
