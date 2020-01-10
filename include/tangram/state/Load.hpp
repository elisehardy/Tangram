#ifndef MAIN_LOAD_HPP
#define MAIN_LOAD_HPP

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <tangram/gui/Drawable.hpp>
#include <tangram/game/Updatable.hpp>
#include <tangram/game/Engine.hpp>
#include <tangram/gui/ShapePreview.hpp>
#include <tangram/gui/Button.hpp>
#include <tangram/state/StateAbstract.hpp>


namespace tangram::state {
    
    class Load : public StateAbstract {
        
        private:
            std::unordered_map<std::string, gui::ShapePreview> previews;
            std::unordered_map<std::string, gui::Button> prevButtons;
            std::vector<std::string> prevOrder;
            std::unique_ptr<gui::Button> next;
            std::unique_ptr<gui::Button> prev;
            uint16_t page = 0;
            
            Load() = default;
            
            void init() override;
        
        public:
            static Load *getInstance();
            
            void pause() override;
            
            void resume() override;
            
            void cleanup() override;
            
            void update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif // MAIN_LOAD_HPP
