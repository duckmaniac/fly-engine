#ifndef CAMERA_3D_H
#define	CAMERA_3D_H

#include "Camera.h"

class Camera3D : public Camera {
private:
	Point3D position_;
	double focal_length_;

private:
	Point2D make_perspective_projection(Point3D point) const;

public:
	Camera3D(const Point3D& position, const Size& resolution, double focal_length);

	// Takes a picture of an object.
	Mesh2D get_perspective_projection(const Mesh3D& mesh) const;

	// Moves camera.
	void set_position(const Point3D& new_position);
};

#endif // CAMERA_3D_H