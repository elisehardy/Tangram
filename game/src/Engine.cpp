#include "../include/Engine.hpp"

#include "../../state/include/StateAbstract.hpp"

using namespace tangram;

void game::Engine::init() {}


void game::Engine::cleanup() {}


void game::Engine::pushState(state::StateAbstract *state) {}


void game::Engine::popState() {}


void game::Engine::update(const game::Event &event) {}


void game::Engine::draw() {}


bool game::Engine::isRunning() {
    return false;
}


void game::Engine::stop() {}
