#ifndef RENDERER_H
#define RENDERER_H

#include "SFML/Graphics.hpp"
#include "Camera2D.h"
#include "Camera3D.h"
#include "Colors.h"

class Renderer {
private:
	std::shared_ptr<Camera> p_camera_;
	sf::RenderWindow& window_;
	Size window_size_;

	// Render line stages: buffer -> texture -> canvas.
	sf::Image buffer_;
	sf::Texture texture_;
	sf::Sprite canvas_;

private:
	bool is_point_within_window(Point2D point) const;

	// Increase line rasterization algorith.
	void draw_line(Point2D start, Point2D end, sf::Color line_color);

public:
	Renderer(std::shared_ptr<Camera> p_camera, sf::RenderWindow& window);

	void draw(const sf::Drawable& object);
	void draw(const Mesh2D& object);
	void draw(const Mesh3D& object);

	void display_frame() const;
	void clear_frame();
};

#endif // RENDERER_H