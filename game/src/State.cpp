#include "../include/State.hpp"

namespace Tangram::Game;


void changeState(Engine *engine, State *state) {
    engine->changeState(state);
}
