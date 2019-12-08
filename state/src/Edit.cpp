#include "../include/Edit.hpp"


using namespace tangram;
using namespace tangram::state;

Edit Edit::instance = Edit();


void Edit::init() {
    this->player = geometry::Shape::square(geometry::Point(100, 100));
    this->initialized = true;
}


Edit *Edit::getInstance() {
    if (!Edit::instance.initialized) {
        Edit::instance.init();
    }
    return &Edit::instance;
}


void Edit::draw() {
    MLV_clear_window(MLV_COLOR_BLACK);
    std::for_each(this->drawables.begin(), this->drawables.end(), [](gui::Drawable *d) { d->draw(); });
    this->player.draw();
}


void Edit::update(const game::Event &event, game::Engine &engine) {
    observer.notify(event, engine);
    this->player.update(event, engine);
}


void Edit::cleanup() {
}


void Edit::pause() {
}


void Edit::resume() {
}
