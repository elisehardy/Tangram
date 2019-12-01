#include "../include/Engine.hpp"


void Game::Engine::init() {
    MLV_create_window("Tangram", nullptr, WIDTH, HEIGHT);
    MLV_change_frame_rate(120);
    this->running = true;
}


void Game::Engine::cleanup() {
    while (!this->states.empty()) {
        this->states.back()->cleanup();
        this->states.pop_back();
    }
    
    MLV_free_window();
}


void Game::Engine::pushState(State::StateAbstract *state) {
    if (!this->states.empty()) {
        this->states.back()->pause();
    }
    
    this->states.push_back(state);
}


void Game::Engine::popState() {
    if (!this->states.empty()) {
        this->states.back()->cleanup();
        this->states.pop_back();
    }
    
    if (!this->states.empty()) {
        this->states.back()->resume();
    }
}


void Game::Engine::update(const Game::Event &event) {
    this->states.back()->update(event, *this);
}


void Game::Engine::draw() {
    this->states.back()->draw();
    MLV_actualise_window();
    MLV_delay_according_to_frame_rate();
}


bool Game::Engine::isRunning() {
    return !this->running;
}


void Game::Engine::stop() {
    this->running = false;
}
