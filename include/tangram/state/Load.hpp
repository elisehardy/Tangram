#ifndef MAIN_LOAD_HPP
#define MAIN_LOAD_HPP

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <tangram/game/Updatable.hpp>
#include <tangram/game/Engine.hpp>
#include <tangram/gui/ButtonText.hpp>
#include <tangram/gui/ButtonDraw.hpp>
#include <tangram/gui/Drawable.hpp>
#include <tangram/gui/ShapePreview.hpp>
#include <tangram/state/State.hpp>
#include <tangram/state/ShapeLoaderState.hpp>


namespace tangram::state {
    
    class Load : public State {
        
        private:
            std::unordered_map<std::string, gui::ShapePreview> previews;
            std::unordered_map<std::string, gui::ButtonText> prevButtons;
            std::unordered_map<std::string, gui::ButtonDraw> delButtons;
            std::unique_ptr<gui::ButtonText> next;
            std::unique_ptr<gui::ButtonText> prev;
            std::unique_ptr<gui::ButtonText> menu;
            ShapeLoaderState *nextState = nullptr;
            std::vector<std::string> prevOrder;
            uint16_t page = 0;
            
            Load() = default;
            
            static bool deleteShape(game::Engine &engine, const std::string &s);
            
            void init() override;
        
        public:
            static Load *getInstance();
            
            Load *setNextState(ShapeLoaderState *nextState);
            
            void pause() override;
            
            void resume() override;
            
            void cleanup() override;
            
            bool update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif // MAIN_LOAD_HPP
