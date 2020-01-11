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
#include <tangram/state/StateAbstract.hpp>


namespace tangram::state {
    
    class Load : public StateAbstract {
        
        private:
            std::unordered_map<std::string, gui::ShapePreview> previews;
            std::unordered_map<std::string, gui::ButtonText> prevButtons;
            std::unordered_map<std::string, gui::ButtonDraw> delButtons;
            std::unique_ptr<gui::ButtonText> next;
            std::unique_ptr<gui::ButtonText> prev;
            std::vector<std::string> prevOrder;
            uint16_t page = 0;
            
            Load() = default;
            
            static void drawDelButton(int16_t x, int16_t y, int16_t w, int16_t h);
        
            static void drawHDelButton(int16_t x, int16_t y, int16_t w, int16_t h);
        
            static void drawCDelButton(int16_t x, int16_t y, int16_t w, int16_t h);
        
            static bool deleteShape(game::Engine &engine, const std::string &s);
        
            void init() override;
        
        public:
            static Load *getInstance();
            
            void pause() override;
            
            void resume() override;
            
            void cleanup() override;
            
            bool update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
            
            void erase(const std::string& path);
    };
}

#endif // MAIN_LOAD_HPP
