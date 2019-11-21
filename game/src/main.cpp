#include "../include/Engine.hpp"


int main(int argc, char **argv) {
    Tangram::Game::Engine game;
    
    // initialize the engine
    game.init();
    
    // load the intro
    
    // main loop
    while (!game.over()) {
        game.handleEvents();
        game.update();
        game.draw();
    }
    
    // cleanup the engine
    game.cleanup();
    return 0;
}
