#include "../include/Load.hpp"


using namespace tangram;
using namespace tangram::state;

Load Load::instance = Load();


void Load::init() {}


Load *Load::getInstance() {
    return nullptr;
}


void Load::draw() const {}


void Load::update(const game::Event &event, game::Engine &engine) {}


void Load::cleanup() {}


void Load::pause() {}


void Load::resume() {}
