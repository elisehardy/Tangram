#include "../include/Engine.hpp"
#include "../include/State.hpp"


using namespace Tangram::Game;


void Engine::init() {
    MLV_create_window("Tangram", nullptr, WIDTH, HEIGHT);
    
    this->running = true;
}


void Engine::cleanup() {
    while (!this->states.empty()) {
        this->states.back()->cleanup();
        this->states.pop_back();
    }
    
    MLV_free_window();
}


void Engine::pushState(State *state) {
    if (!this->states.empty()) {
        this->states.back()->pause();
    }
    
    this->states.push_back(state);
    this->states.back()->init();
}


void Engine::popState() {
    if (!this->states.empty()) {
        this->states.back()->cleanup();
        this->states.pop_back();
    }
    
    if (!this->states.empty()) {
        this->states.back()->resume();
    }
}


void Engine::handleEvents() {
    this->states.back()->handleEvents();
}


void Engine::update() {
    this->states.back()->update();
}


void Engine::draw() {
    this->states.back()->draw();
}


bool Engine::over() {
    return !this->running;
}
