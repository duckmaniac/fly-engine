#include "Scene.h"

Scene::Scene(std::string name) : name_{ name } {}

void Scene::add_object(std::shared_ptr<Object> p_object) {
    objects_.push_back(p_object);
    auto p_clickable = std::dynamic_pointer_cast<Clickable>(p_object);
    if (p_clickable) {
        clickable_objects_.push_back(p_clickable);
    }
}

void Scene::add_objects(const std::vector<std::shared_ptr<Object>>& objects) {
    for (auto object : objects) {
        add_object(object);
    }
}

void Scene::render() {
    p_renderer_->clear_frame();
    for (auto p_object : objects_) {
        p_object->render(*p_renderer_);
    }
    p_renderer_->display_frame();
}

void Scene::init(sf::RenderWindow& window) {
    p_renderer_ = new Renderer{p_camera_, window};
}

const std::string& Scene::get_name() const {
    return name_;
}