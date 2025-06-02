#pragma once

/**
 * Klasse Updatable ist eine abstrakte Klasse, welche Objekte definiert, die, in der regel, nach jedem Frame
 * geupdated werden sollen
 */
class Updatable {
public:
    Updatable() = default;
    virtual ~Updatable() = default;

    /**
     * Die Updatefunktion die das Objekt updated
     */
    virtual void update() = 0;
};