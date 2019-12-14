#include "../include/Edit.hpp"

#include <algorithm>


using namespace tangram;
using namespace tangram::state;

Edit Edit::instance = Edit();


void Edit::init() {
    this->player = geometry::Shape::square(geometry::Point16(100, 100));
    this->updatables.push_back(&this->player);
    this->drawables.push_back(&this->player);
    this->initialized = true;
}


Edit *Edit::getInstance() {
    if (!Edit::instance.initialized) {
        Edit::instance.init();
    }
    return &Edit::instance;
}


void Edit::draw() const {
    MLV_clear_window(MLV_COLOR_BLACK);
    std::for_each(
            this->drawables.begin(), this->drawables.end(),
            [](gui::Drawable *d) { d->draw(); }
    );
}


void Edit::update(const game::Event &event, game::Engine &engine) {
    std::for_each(
            this->updatables.begin(), this->updatables.end(),
            [&](game::Updatable *u) { u->update(event, engine); }
    );
}


void Edit::cleanup() {
}


void Edit::pause() {
}


void Edit::resume() {
}
