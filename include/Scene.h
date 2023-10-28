#ifndef SCENE_H
#define	SCENE_H

#include "Object.h"
#include "Clickable.h"

class Scene {
protected:
	std::string name_;
	std::shared_ptr<Camera> p_camera_;
	Renderer* p_renderer_;

	std::vector<std::shared_ptr<Object>> objects_;
	std::vector<std::shared_ptr<Clickable>> clickable_objects_;

protected:
	void add_object(std::shared_ptr<Object> object);
	void add_objects(const std::vector<std::shared_ptr<Object>>& objects);

public:
	Scene(std::string name);

	virtual void update(float delta_time) = 0;
	void render();

	void init(sf::RenderWindow& window);
	const std::string& get_name() const;
};

#endif // SCENE_H