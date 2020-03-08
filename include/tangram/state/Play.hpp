/** @file Play.hpp
 *
 *  @brief ***Play***'s header
 *
 *  @author Elise Hardy
 *  @author Quentin Coumes
 */
 
#ifndef PLAY_HPP
#define PLAY_HPP

#include <vector>
#include <memory>

#include <tangram/gui/Drawable.hpp>
#include <tangram/geometry/Shape.hpp>
#include <tangram/geometry/Polygon.hpp>
#include <tangram/game/Engine.hpp>
#include <tangram/game/Updatable.hpp>
#include <tangram/state/State.hpp>
#include <tangram/state/ShapeLoaderState.hpp>
#include <tangram/gui/ShapePreview.hpp>


namespace tangram::state {
    
    /**
     * State representing the main game.
     */
    class Play : public ShapeLoaderState {
        
        private:
            static constexpr int16_t MENU_SEPARATOR = game::HEIGHT;
            
            std::vector<std::shared_ptr<game::Updatable>> updatables = {};
            std::vector<std::shared_ptr<gui::Drawable>> drawables = {};
            geometry::Shape player = geometry::Shape();
            geometry::Shape goal = geometry::Shape();
            geometry::Shape shadow = geometry::Shape();
            bool success = false;
            std::string title;
            
            Play() = default;
            
            void init() override;
        
        public:
            
            /**
             * Return the instance of the Singleton corresponding to this State.
             *
             * @return The instance of the Singleton corresponding to this State.
             */
            static Play *getInstance();
            
            Play *loadShape(const std::string &path) override;
            
            void pause() override;
            
            void resume() override;
            
            void cleanup() override;
            
            bool update(const game::Event &event, game::Engine &engine) override;
            
            void draw() const override;
    };
}

#endif // PLAY_HPP
