#include "Object3D.h"

Object3D::Object3D(const Point3D& position) : position_{ position } {}

Point3D Object3D::rotate_point_along_x(const Point3D& point, float angle) {
	return {
		point.x,
		cos(angle) * point.y - sin(angle) * point.z,
		sin(angle) * point.y + cos(angle) * point.z,
	};
}

Point3D Object3D::rotate_point_along_y(const Point3D& point, float angle) {
	return {
		cos(angle) * point.x - sin(angle) * point.z,
		point.y,
		sin(angle) * point.x + cos(angle) * point.z
	};
}

Point3D Object3D::rotate_point_along_z(const Point3D& point, float angle) {
	return {
		cos(angle) * point.x - sin(angle) * point.y,
		sin(angle) * point.x + cos(angle) * point.y,
		point.z
	};
}

void Object3D::render(Renderer& renderer) const {
	renderer.draw(mesh_);
}

void Object3D::rotate_along_x(float angle) {
	for (auto& line : mesh_) {
		line.first = rotate_point_along_x(line.first, angle);
		line.second = rotate_point_along_x(line.second, angle);
	}
}

void Object3D::rotate_along_y(float angle) {
	for (auto& line : mesh_) {
		line.first = rotate_point_along_y(line.first, angle);
		line.second = rotate_point_along_y(line.second, angle);
	}
}

void Object3D::rotate_along_z(float angle) {
	for (auto& line : mesh_) {
		line.first = rotate_point_along_z(line.first, angle);
		line.second = rotate_point_along_z(line.second, angle);
	}
}