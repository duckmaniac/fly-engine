#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include "Resources.h"
#include "Scene.h"

class Application {
private:
	std::map<std::string, std::shared_ptr<Scene>> scenes_;
	std::shared_ptr<Scene> p_current_scene_;
	sf::RenderWindow window_;
	sf::Event event_;
	sf::Clock clock_;
	sf::Vector2i mouse_position_;

private:
	virtual void update();
	virtual void render();
	virtual void polling_events();
	virtual void update_mouse_position();

public:
	Application(std::string title, Size window_size, int fps_limit);

	// Application's main cycle.
	void start();
	const bool is_running() const;

	// Scene management.
	void add_scene(std::shared_ptr<Scene> scene);
	void load_scene(std::string scene_name);

	// Resource management.
	void set_icon(const sf::Image& icon);
	template <typename T>
	T load_resource(const std::string& resource_name);
};

template<typename T>
inline T Application::load_resource(const std::string& resource_name)
{
	T resource = T();
	EmbeddedResource data = load_embedded_resource(resource_name);
	if (!resource.loadFromMemory(data.p_resource, data.size_in_memory)) {
		throw std::runtime_error("Failed to load resource: " + resource_name);
	}

	return resource;
}

#endif // APPLICATION_H