#include "../include/Play.hpp"


using namespace State;

Play Play::instance = Play();


void Play::init() {
    // TODO interface
    this->initialized = true;
}


Play *Play::getInstance() {
    if (!Play::instance.initialized) {
        Play::instance.init();
    }
    return &Play::instance;
}


void Play::draw() {
    MLV_clear_window(MLV_COLOR_GREY80);
    std::for_each(this->drawables.begin(), this->drawables.end(), [](GUI::Drawable *d) { d->draw(); });
    this->player.draw();
    MLV_actualise_window();
}


void Play::update(const Game::Event &event, Game::Engine &engine) {
    observer.notify(event, engine);
}


void Play::cleanup() {
}


void Play::pause() {
}


void Play::resume() {
}


