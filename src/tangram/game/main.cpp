#include <tangram/game/Engine.hpp>
#include <tangram/state/Menu.hpp>


using namespace tangram;


int main(int argc, char **argv) {
    game::Engine game;
    
    game.init();
    game.pushState(state::Menu::getInstance());
    
    while (game.isRunning()) {
        game.update(game::Event::get());
        game.draw();
    }
    
    game.cleanup();
    
    return 0;
}
