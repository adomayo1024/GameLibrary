#pragma once

#include <memory>
#include <vector>
#include "Updatable.h"

namespace myGE {
/**
 * Manager der sich darum kümmert in jedem Frame alle Elemente zu updaten.
 *  Jedes Element, was geupdatet werden möchte, muss sich hier vorher anmelden.
 */
class UpdateManager {

public:
    /**
     * Konstruktor der ein UpdateManager instanziiert.
     */
    UpdateManager();

    /**
     * Wird jeden Frame ausgeführt und updated alle Objekte, die sich angemeldet haben.
     */
    void update();

    /**
     * Meldet ein Element an was geupdatet werden möchte jeden Frame
     * @param element das Element, was sich anmelden möchte
     */
    void setUpdateObj(std::shared_ptr<myGE::Updatable>& element);

private:
    /**
     * Die Liste mit allen Elementen, die geupdatet werden möchten
     */
    std::vector<std::shared_ptr<myGE::Updatable>> updatables;
};
}