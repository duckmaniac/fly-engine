#include "Camera3D.h"

Camera3D::Camera3D(const Point3D& position, const Size& resolution, double focal_length) :
	Camera{ resolution },
	position_{ position },
	focal_length_{ focal_length } {}

Point2D Camera3D::make_perspective_projection(Point3D point) const {
	// Go to the camera coordinate system.
	point -= position_;

	return Point2D(
		round(point.x * focal_length_ / point.z),
		round(point.y * focal_length_ / point.z)
	);
}

Mesh2D Camera3D::get_perspective_projection(const Mesh3D& mesh) const {
	Mesh2D projection;
	for (const Line3D& line : mesh) {
		projection.push_back(
			std::make_pair(
				make_perspective_projection(line.first),
				make_perspective_projection(line.second)
			)
		);
	}

	return projection;
}

void Camera3D::set_position(const Point3D& new_position) {
	position_ = new_position;
}