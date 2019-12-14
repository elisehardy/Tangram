
#ifndef LOAD_H
#define LOAD_H

#include "StateAbstract.hpp"
#include "../../gui/include/Drawable.hpp"
#include "../../gui/include/Button.hpp"

#include "../../geometry/include/Shape.hpp"
#include "../../game/include/Engine.hpp"

#include "../../game/include/Updatable.hpp"

namespace tangram::state {

    class Load : public StateAbstract {
    private:
        static Load instance;

        Load() = default;

        void init() override;

    public:
        static Load *getInstance();
        void cleanup() override;
        void pause() override;
        void resume() override;
        void update(const game::Event &event, game::Engine &engine) override;
        void draw() const override;
    };
}

#endif //LOAD_H
