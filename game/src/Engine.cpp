#include "../include/Engine.hpp"


using namespace Tangram;


void Game::Engine::init() {
    MLV_create_window("Tangram", nullptr, WIDTH, HEIGHT);
    
    this->running = true;
}


void Game::Engine::cleanup() {
    while (!this->states.empty()) {
        this->states.back()->cleanup();
        this->states.pop_back();
    }
    
    MLV_free_window();
}


void Game::Engine::pushState(State::StateAbstract*state) {
    if (!this->states.empty()) {
        this->states.back()->pause();
    }
    
    this->states.push_back(state);
    this->states.back()->init();
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


void Game::Engine::handleEvents() {
    this->states.back()->handleEvents();
}


void Game::Engine::update() {
    this->states.back()->update();
}


void Game::Engine::draw() {
    this->states.back()->draw();
}


bool Game::Engine::over() {
    return !this->running;
}
