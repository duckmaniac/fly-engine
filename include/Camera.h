#ifndef CAMERA_H
#define	CAMERA_H

#include "Geometry.h"

class Camera {
private:
	Size resolution_;

protected:
	Camera(const Size& resolution);
	virtual ~Camera() = default;
};

#endif // CAMERA_H