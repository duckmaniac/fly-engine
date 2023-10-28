#include "Camera2D.h"

Camera2D::Camera2D(const Point2D& position, const Size& resolution) : 
	Camera{ resolution }, position_{ position } {}

void Camera2D::set_position(const Point2D& new_position) {
	position_ = new_position;
}