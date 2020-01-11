#ifndef Edit_HPP
#define Edit_HPP

#include <vector>
#include <memory>

#include <tangram/game/Updatable.hpp>
#include <tangram/geometry/Shape.hpp>
#include <tangram/gui/Drawable.hpp>
#include <tangram/state/StateAbstract.hpp>


namespace tangram::state {
    
    class Edit : public StateAbstract {
        
        private:
            static constexpr int16_t MENU_SEPARATOR = game::HEIGHT;
        
        private:
            std::vector<std::shared_ptr<game::Updatable>> updatables;
            std::vector<std::shared_ptr<gui::Drawable>> drawables;
            geometry::Shape player = geometry::Shape();
            std::string title;
            
            Edit() = default;
            
            void init() override;
            
            static bool save(game::Engine &engine);
        
        public:
            static Edit *getInstance();
        
            Edit *loadShape(const std::string& path);
        
            void cleanup() override;
        
            void pause() override;
        
            void resume() override;
        
            bool update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif // Edit_HPP
