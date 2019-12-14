#include "../include/Edit.hpp"

using namespace tangram;
using namespace tangram::state;

Edit Edit::instance = Edit();


void Edit::init() {}


Edit *Edit::getInstance() {
    return nullptr;
}


void Edit::draw() const {}


void Edit::update(const game::Event &event, game::Engine &engine) {}


void Edit::cleanup() {}


void Edit::pause() {}


void Edit::resume() {}
