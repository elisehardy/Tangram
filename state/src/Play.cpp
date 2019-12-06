#include "../include/Play.hpp"


using namespace tangram::state;

Play Play::instance = Play();


void Play::init() {
    this->player = shape::ShapeSet(shape::Point(100, 100));
    this->goal = shape::ShapeSet(shape::Point(100, 100));
    this->initialized = true;
    
    for (shape::Shape *p: this->player) {
        this->observer.add(p);
    }
}


Play *Play::getInstance() {
    if (!Play::instance.initialized) {
        Play::instance.init();
    }
    return &Play::instance;
}


void Play::draw() {
    MLV_clear_window(MLV_COLOR_GREY80);
    std::for_each(this->drawables.begin(), this->drawables.end(), [](gui::Drawable *d) { d->draw(); });
    this->player.draw();
}


void Play::update(const game::Event &event, game::Engine &engine) {
    observer.notify(event, engine);
}


void Play::cleanup() {
}


void Play::pause() {
}


void Play::resume() {
}



