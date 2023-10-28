#ifndef CLICKABLE_H
#define CLICKABLE_H

#include "Geometry.h"

class Clickable {
public:
    virtual bool does_point_belong_object(const Point2D& point) const = 0;
    virtual void on_mouse_pressed() = 0;
    virtual void on_mouse_released() = 0;
};

#endif // CLICKABLE_H