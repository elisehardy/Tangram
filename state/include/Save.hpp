#ifndef SAVE_H
#define SAVE_H

#include "../../gui/include/Drawable.hpp"
#include "../../gui/include/Button.hpp"

#include "../../geometry/include/Shape.hpp"
#include "../../game/include/Engine.hpp"

#include "../../game/include/Updatable.hpp"
#include "StateAbstract.hpp"


namespace tangram::state {

    class Save : public StateAbstract {
    private:
        static Save instance;

        Save() = default;

        void init() override;

    public:
        static Save *getInstance();
        void cleanup() override;
        void pause() override;
        void resume() override;
        void update(const game::Event &event, game::Engine &engine) override;
        void draw() const override;
    };
}

#endif //SAVE_H
