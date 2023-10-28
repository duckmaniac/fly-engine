#ifndef CAMERA_2D_H
#define	CAMERA_2D_H

#include "Camera.h"

class Camera2D : public Camera {
private:
	Point2D position_;

public:
	Camera2D(const Point2D& position, const Size& resolution);

	// Moves camera.
	void set_position(const Point2D& new_position);
};

#endif // CAMERA_2D_H