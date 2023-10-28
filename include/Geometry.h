#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>
#include "SFML/System/Vector2.hpp"
#include "SFML/System/Vector3.hpp"

using Point3D = sf::Vector3f;
using Line3D = std::pair<Point3D, Point3D>;
using Mesh3D = std::vector<Line3D>;

using Point2D = sf::Vector2f;
using Line2D = std::pair<Point2D, Point2D>;
using Mesh2D = std::vector<Line2D>;

using Size = struct {
	unsigned int width;
	unsigned int height;
};
	
#endif // GEOMETRY_H