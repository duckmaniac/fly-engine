#include "Application.h"

Application::Application(
    std::string title, 
    Size window_size,
    int fps_limit
) : window_{ sf::VideoMode(window_size.width, window_size.height), title, sf::Style::Titlebar | sf::Style::Close },
    event_{ sf::Event() } {
    window_.setFramerateLimit(fps_limit);
}

void Application::update() {
    polling_events();
    update_mouse_position();

    p_current_scene_->update(clock_.getElapsedTime().asSeconds());
    clock_.restart();
}

void Application::render() {
    p_current_scene_->render();
}

void Application::polling_events() {
    // Event polling.
    while (window_.pollEvent(event_)) {
        switch (event_.type) {
            // Process window closing.
            case sf::Event::Closed:
                window_.close();
                break;

            // Process pressed keys.
            case sf::Event::KeyPressed:
                switch (event_.key.code) {
                case sf::Keyboard::Escape:
                    window_.close();
                    break;
                }

            // Process mouse button click.
            /*case sf::Event::MouseButtonPressed: {
                if (event_.mouseButton.button == sf::Mouse::Left) {
                    for (auto object : clickable_objects_) {
                        if (object->does_point_belong_object(mouse_position_)) {
                            object->get_click_handler().on_mouse_pressed();
                            break;
                        }
                    }
                }
                break;
            }
            case sf::Event::MouseButtonReleased: {
                if (event_.mouseButton.button == sf::Mouse::Left) {
                    for (auto object : clickable_objects_) {
                        object->get_click_handler().on_mouse_released();
                    }
                }
                break;
            }*/
        }
    }
}

void Application::update_mouse_position() {
    mouse_position_ = sf::Mouse::getPosition(window_);
}

void Application::start() {
    while (is_running() && p_current_scene_) {
        update();
        render();
    }
}

const bool Application::is_running() const {
    return window_.isOpen();
}

void Application::add_scene(std::shared_ptr<Scene> p_scene) {
    p_scene->init(window_);
    scenes_.insert({ p_scene->get_name(), p_scene });
}

void Application::load_scene(std::string scene_name) {
    if (scenes_.find(scene_name) != scenes_.end()) {
        p_current_scene_ = scenes_[scene_name];
    }
    else {
        throw std::runtime_error("Scene name not found!");
    }
}

void Application::set_icon(const sf::Image& icon) {
    window_.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}