#include "../include/Edit.hpp"


using namespace State;

Edit Edit::instance = Edit();


void Edit::init() {
    this->player = Shape::ShapeSet(Shape::Point(100, 100));
    this->goal = Shape::ShapeSet(Shape::Point(100, 100));
    this->initialized = true;

    for (Shape::Polygon *p: this->player) {
        this->observer.add(p);
    }
}


Edit *Edit::getInstance() {
    if (!Edit::instance.initialized) {
        Edit::instance.init();
    }
    return &Edit::instance;
}


void Edit::draw() {
    MLV_clear_window(MLV_COLOR_BLACK);
    std::for_each(this->drawables.begin(), this->drawables.end(), [](GUI::Drawable *d) { d->draw(); });
    this->player.draw();
}


void Edit::update(const Game::Event &event, Game::Engine &engine) {
    observer.notify(event, engine);
}


void Edit::cleanup() {
}


void Edit::pause() {
}


void Edit::resume() {
}



