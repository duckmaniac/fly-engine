#ifndef OBJECT_2D_H
#define	OBJECT_2D_H

#include "Object.h"

class Object2D : public Object {
protected:
    Point2D position_; // 2D position of the object.
    Size size_; // Size of the bounding box.

public:
    Object2D(const Point2D& position, const Size& size);

    // Calculates the boundary of the object.
    // @return coordinates of the left-upper corner and the right-bottom corner of the bounding box.
    std::pair<Point2D, Point2D> get_global_bounds() const;
};

#endif // OBJECT_2D_H