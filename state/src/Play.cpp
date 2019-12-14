#include "../include/Play.hpp"


using namespace tangram;
using namespace tangram::state;

Play Play::instance = Play();


void Play::init() {}


Play *Play::getInstance() {
    return nullptr;
}


void Play::draw() const {}


void Play::update(const game::Event &event, game::Engine &engine) {}


void Play::cleanup() {}


void Play::pause() {}


void Play::resume() {}



