#include <tangram/game/Engine.hpp>

#include <tangram/state/StateAbstract.hpp>


namespace tangram::game {
    
    void Engine::init() {
        MLV_create_window("Tangram", nullptr, WIDTH, HEIGHT);
        MLV_change_frame_rate(240);
        this->running = true;
    }
    
    
    void Engine::cleanup() {
        while (!this->states.empty()) {
            this->states.back()->cleanup();
            this->states.pop_back();
        }
        
        MLV_free_window();
    }
    
    
    bool Engine::pushState(state::StateAbstract *state) {
        if (!this->states.empty()) {
            this->states.back()->pause();
        }
        
        this->states.push_back(state);
        return true;
    }
    
    
    bool Engine::popState() {
        if (!this->states.empty()) {
            this->states.back()->cleanup();
            this->states.pop_back();
        }
        
        if (!this->states.empty()) {
            this->states.back()->resume();
        }
        
        return true;
    }
    
    
    state::StateAbstract *Engine::current() {
        return this->states.back();
    }
    
    
    void Engine::update(const Event &event) {
        
        this->states.back()->update(event, *this);
        if (this->states.empty()) {
            this->stop();
        }
    }
    
    
    void Engine::draw() {
        if (!this->states.empty()) {
            this->states.back()->draw();
        }
        MLV_actualise_window();
        MLV_delay_according_to_frame_rate();
    }
    
    
    bool Engine::isRunning() {
        return this->running;
    }
    
    
    bool Engine::stop() {
        this->running = false;
        return true;
    }
}
