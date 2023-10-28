#ifndef OBJECT_H
#define OBJECT_H

#include "Renderer.h"

// Base class for any drawable object within the game or application.
class Object {
public:
    Object() = default;
    virtual ~Object() = default;

    // Updates the state of the object.
    virtual void update() = 0;

    // Renders the object.
    virtual void render(Renderer& renderer) const = 0;
};

#endif // OBJECT_H