#include <tangram/game/Engine.hpp>
#include <tangram/state/State.hpp>


namespace tangram::game {
    
    void Engine::init() {
        MLV_create_window("Tangram", nullptr, WIDTH, HEIGHT);
        MLV_change_frame_rate(FRAME_RATE);
        this->running = true;
    }
    
    
    void Engine::cleanup() {
        while (!this->states.empty()) {
            this->states.top()->cleanup();
            this->states.pop();
        }
        
        MLV_free_window();
    }
    
    
    bool Engine::pushState(state::State *state) {
        if (!this->states.empty()) {
            this->states.top()->pause();
        }
        
        this->states.push(state);
        return true;
    }
    
    
    bool Engine::popState() {
        if (!this->states.empty()) {
            this->states.top()->cleanup();
            this->states.pop();
        }
        
        if (!this->states.empty()) {
            this->states.top()->resume();
        }
        
        return true;
    }
    
    
    void Engine::update(const Event &event) {
        this->states.top()->update(event, *this);
        if (this->states.empty()) {
            this->stop();
        }
    }
    
    
    void Engine::draw() {
        if (!this->states.empty()) {
            this->states.top()->draw();
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
