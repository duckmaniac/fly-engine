#include "Renderer.h"

Renderer::Renderer(std::shared_ptr<Camera> p_camera, sf::RenderWindow& window) : 
	p_camera_{ p_camera }, window_{ window }, window_size_{ window.getSize().x, window.getSize().y } {
	buffer_.create(window_size_.width, window_size_.height, Colors::BACKGROUND);
	texture_.loadFromImage(buffer_);
	canvas_.setTexture(texture_);
}

bool Renderer::is_point_within_window(Point2D point) const {
	return (0 <= point.x && point.x <= window_size_.width) && 
		(0 <= point.y && point.y <= window_size_.height);
}

// Draws the line using Bresenham's algorithm.
void Renderer::draw_line(Point2D start, Point2D end, sf::Color line_color) {
    if (!is_point_within_window(start) || !is_point_within_window(end)) return;

    int dx = end.x - start.x;
    int dy = end.y - start.y;
    int stepX = (dx > 0) ? 1 : (dx < 0) ? -1 : 0; // Determine direction in X
    int stepY = (dy > 0) ? 1 : (dy < 0) ? -1 : 0; // Determine direction in Y

    // Handle vertical lines.
    if (stepX == 0) {
        for (int v = start.y; v != end.y + stepY; v += stepY) {
            buffer_.setPixel(start.x, v, line_color);
        }
        return;
    }

    dx = abs(dx);
    dy = abs(dy);

    // Sampling along y-axis.
    if (dy > dx) {
        int d = (2 * dx) - dy;
        int u = start.x;
        for (int v = start.y; v != end.y + stepY; v += stepY) {
            buffer_.setPixel(u, v, line_color);
            if (d > 0) {
                u += stepX;
                d -= 2 * dy;
            }
            d += 2 * dx;
        }
    }
    // Sampling along x-axis.
    else {
        int d = (2 * dy) - dx;
        int v = start.y;
        for (int u = start.x; u != end.x + stepX; u += stepX) {
            buffer_.setPixel(u, v, line_color);
            if (d > 0) {
                v += stepY;
                d -= 2 * dx;
            }
            d += 2 * dy;
        }
    }

    texture_.loadFromImage(buffer_);
}


void Renderer::draw(const sf::Drawable& object) {
	window_.draw(object);
}

void Renderer::draw(const Mesh2D& object) {
	for (const Line2D& line : object) {
		draw_line(line.first, line.second, Colors::MESH_COLOR);
	}
	draw(canvas_);

	// Clear the buffer after drawing it.
	buffer_.create(window_size_.width, window_size_.height, Colors::BACKGROUND);
}

void Renderer::draw(const Mesh3D& object) {
	auto p_camera_3d = std::dynamic_pointer_cast<Camera3D>(p_camera_);
	if (!p_camera_3d) throw std::runtime_error("Ñamera3D must be created in the scene with 3D objects!");
	Mesh2D projection = p_camera_3d->get_perspective_projection(object);
	draw(projection);
}

void Renderer::display_frame() const {
	window_.display();
}

void Renderer::clear_frame() {
	window_.clear(Colors::BACKGROUND);
}