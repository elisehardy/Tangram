#include "../include/Engine.hpp"

#include "../../state/include/StateAbstract.hpp"


using namespace tangram;


void game::Engine::init() {
    MLV_create_window("Tangram", nullptr, WIDTH, HEIGHT);
    MLV_change_frame_rate(240);
    this->running = true;
}


void game::Engine::cleanup() {
    while (!this->states.empty()) {
        this->states.back()->cleanup();
        this->states.pop_back();
    }
    
    MLV_free_window();
}


void game::Engine::pushState(state::StateAbstract *state) {
    if (!this->states.empty()) {
        this->states.back()->pause();
    }
    
    this->states.push_back(state);
}


void game::Engine::popState() {
    if (!this->states.empty()) {
        this->states.back()->cleanup();
        this->states.pop_back();
    }
    
    if (!this->states.empty()) {
        this->states.back()->resume();
    }
}


void game::Engine::update(const game::Event &event) {
    this->states.back()->update(event, *this);
}


void game::Engine::draw() {
    this->states.back()->draw();
    MLV_actualise_window();
    MLV_delay_according_to_frame_rate();
}


bool game::Engine::isRunning() {
    return !this->running;
}


void game::Engine::stop() {
    this->running = false;
}
