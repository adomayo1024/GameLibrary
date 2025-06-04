#include "../include/UpdateManager.h"

void myGE::UpdateManager::update() {
        for (const std::shared_ptr<Updatable>& updatable: updatables) {
                updatable->update();
        }
}

myGE::UpdateManager::UpdateManager() : updatables(std::vector<std::shared_ptr<Updatable>>{}) {

}

void myGE::UpdateManager::setUpdateObj(std::shared_ptr<Updatable>& updatable) {
        updatables.push_back(updatable);
}
