#include "Object2D.h"

Object2D::Object2D(const Point2D& position, const Size& size) : 
    position_{ position }, size_{ size } {}

std::pair<Point2D, Point2D> Object2D::get_global_bounds() const {
    return std::pair<Point2D, Point2D>(
        position_,
        sf::Vector2f(position_.x + size_.width, position_.y + size_.height)
    );
}