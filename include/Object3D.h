#ifndef OBJECT_3D_H
#define	OBJECT_3D_H

#include "Object.h"

class Object3D : public Object {
protected:
    Point3D position_; // 3D position of the object.
    Mesh3D mesh_; // Shape of 3D object.

private:
    static Point3D rotate_point_along_x(const Point3D& point, float angle);
    static Point3D rotate_point_along_y(const Point3D& point, float angle);
    static Point3D rotate_point_along_z(const Point3D& point, float angle);

public:
    Object3D(const Point3D& position);

    // Renders the object.
    void render(Renderer& renderer) const override;

    void rotate_along_x(float angle);
    void rotate_along_y(float angle);
    void rotate_along_z(float angle);
};

#endif // OBJECT_3D_H