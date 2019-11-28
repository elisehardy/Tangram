#include "../include/Engine.hpp"
#include "../../state/include/Menu.hpp"

int main(int argc, char **argv) {
    Game::Engine game;
    
    game.init();
    game.pushState(State::Menu::getInstance());
    
    while (!game.over()) {
        game.update(Game::Event::get());
        game.draw();
    }
    
    game.cleanup();
    
    return 0;
}
