#include <tangram/geometry/Shape.hpp>

#include <algorithm>


namespace tangram::geometry {
    
    tangram::geometry::Shape::Shape(std::string path) {
    }
    
    
    Shape Shape::square(const Point16 &offset) {
        static int16_t HYPOTENUSE2 = Triangle::HYPOTENUSE * 2;
        Shape shape;
        
        shape.polygons.push_back(Polygon::custom(
            { Triangle({ 0, 0 }, { Triangle::HYPOTENUSE, Triangle::HYPOTENUSE }, { 0, HYPOTENUSE2 }), },
            MLV_COLOR_PURPLE
        ));
        shape.polygons.push_back(Polygon::custom(
            { Triangle({ 0, 0 }, { Triangle::HYPOTENUSE, Triangle::HYPOTENUSE }, { HYPOTENUSE2, 0 }), },
            MLV_COLOR_RED
        ));
        shape.polygons.push_back(Polygon::custom(
            {
                Triangle(
                    { HYPOTENUSE2, Triangle::HYPOTENUSE },
                    { HYPOTENUSE2, HYPOTENUSE2 },
                    { Triangle::HYPOTENUSE + Triangle::HEIGHT, Triangle::HYPOTENUSE + Triangle::HEIGHT }
                ),
                Triangle(
                    { Triangle::HYPOTENUSE, HYPOTENUSE2 },
                    { HYPOTENUSE2, HYPOTENUSE2 },
                    { Triangle::HYPOTENUSE + Triangle::HEIGHT, Triangle::HYPOTENUSE + Triangle::HEIGHT }
                ),
            },
            MLV_COLOR_GREEN
        ));
        shape.polygons.push_back(Polygon::custom(
            {
                Triangle(
                    { 0, HYPOTENUSE2 },
                    { Triangle::HYPOTENUSE, HYPOTENUSE2 },
                    { Triangle::HEIGHT, Triangle::HYPOTENUSE + Triangle::HEIGHT }
                ),
            },
            MLV_COLOR_ORANGE2
        ));
        shape.polygons.push_back(Polygon::custom(
            {
                Triangle(
                    { Triangle::HYPOTENUSE, Triangle::HYPOTENUSE },
                    { Triangle::HYPOTENUSE + Triangle::HEIGHT, Triangle::HEIGHT },
                    { Triangle::HYPOTENUSE + Triangle::HEIGHT, Triangle::HYPOTENUSE + Triangle::HEIGHT }
                ),
            },
            MLV_COLOR_YELLOW
        ));
        
        shape.polygons.push_back(Polygon::custom(
            {
                Triangle(
                    { Triangle::HYPOTENUSE, Triangle::HYPOTENUSE },
                    { Triangle::HYPOTENUSE + Triangle::HEIGHT, Triangle::HYPOTENUSE + Triangle::HEIGHT },
                    { Triangle::HYPOTENUSE, HYPOTENUSE2 }
                ),
                Triangle(
                    { Triangle::HYPOTENUSE, Triangle::HYPOTENUSE },
                    { Triangle::HEIGHT, Triangle::HYPOTENUSE + Triangle::HEIGHT },
                    { Triangle::HYPOTENUSE, HYPOTENUSE2 }
                )
            },
            MLV_COLOR_WHITE
        ));
        shape.polygons.push_back(Polygon::custom(
            {
                Triangle(
                    { HYPOTENUSE2, 0 },
                    { HYPOTENUSE2, Triangle::HYPOTENUSE },
                    { Triangle::HYPOTENUSE + Triangle::HEIGHT, Triangle::HEIGHT }
                ),
                Triangle(
                    { Triangle::HYPOTENUSE + Triangle::HEIGHT, Triangle::HEIGHT },
                    { Triangle::HYPOTENUSE + Triangle::HEIGHT, Triangle::HYPOTENUSE + Triangle::HEIGHT },
                    { HYPOTENUSE2, Triangle::HYPOTENUSE }
                )
            },
            MLV_COLOR_CYAN
        ));
        
        return shape;
    }
    
    
    Shape Shape::random(Point16 lowerBound, Point16 upperBound) {
        return Shape();
    }
    
    
    Shape &Shape::translate(const Vector16 &v) {
        std::for_each(
            this->polygons.begin(), this->polygons.end(),
            [&](Polygon &p) { p.translate(v); }
        );
        
        return *this;
    }
    
    
    Shape &Shape::translate(int16_t x, int16_t y) {
        return this->translate({ x, y });
    }
    
    
    Shape &Shape::scale(const VectorD &v) {
        std::for_each(
            this->polygons.begin(), this->polygons.end(),
            [&](Polygon &p) { p.scale(v); }
        );
        
        return *this;
    }
    
    
    Shape &Shape::scale(double x, double y) {
        return this->scale({ x, y });
    }
    
    
    Shape &Shape::scale(double factor) {
        return this->scale({ factor, factor });
    }
    
    
    Shape &Shape::setColor(MLV_Color color) {
        std::for_each(
            this->polygons.begin(), this->polygons.end(),
            [&](Polygon &p) { p.setColor(color); }
        );
    
        return *this;
    }
    
    
    bool tangram::geometry::Shape::operator==(const tangram::geometry::Shape &other) const {
        std::vector<Point16> aPoints = this->getPoints(), bPoints = other.getPoints();
        return aPoints.size() == bPoints.size() && std::is_permutation(aPoints.begin(), aPoints.end(), bPoints.begin());
    }
    
    
    std::ostream &operator<<(std::ostream &os, const Shape &s) {
        for (const Polygon &p: s.polygons) {
            os << p << std::endl;
        }
        return os;
    }
    
    
    std::vector<Point16> tangram::geometry::Shape::getPoints() const {
        std::vector<Point16> points = {};
        
        for (const Polygon &p: this->polygons) {
            auto polygonPoints = p.getPoints();
            std::for_each(
                polygonPoints.begin(), polygonPoints.end(),
                [&points](const Point16 &p) { points.emplace_back(p); }
            );
        }
        
        return points;
    }
    
    
    void Shape::addPolygon(const Polygon &polygon) {
        this->polygons.push_back(polygon);
    }
    
    
    void Shape::ensureInbounds(Point16 lowerBound, Point16 upperBound) {
        uint64_t i, size = this->polygons.size();
        
        for (i = 0; i < size; i++) {
            geometry::Point16 upper = { 0, 0 }, lower = { 0, 0 };
            
            for (const geometry::Point16 &p: this->polygons[i].getPoints()) {
                
                upper = {
                    std::min(upper.x, int16_t(upperBound.x - p.x)),
                    std::min(upper.y, int16_t(upperBound.y - p.y))
                };
                lower = {
                    std::max(lower.x, int16_t(lowerBound.x - p.x)),
                    std::max(lower.y, int16_t(lowerBound.y - p.y))
                };
            }
            
            polygons[i].translate(upper).translate(lower);
        }
    }
    
    
    bool tangram::geometry::Shape::update(const tangram::game::Event &event, tangram::game::Engine &engine) {
        bool first = false, flag = false;
        
        for (auto it = this->polygons.rbegin(); it != this->polygons.rend(); ++it) {
            Polygon &p = *it;
            
            p.update(event, engine);
            
            // Moving the Shape
            if (p.isLeftHeld() && !first) {
                flag = true;
                p.translate(event.mousePos - p.getLeftPressedPoint());
            }
            if (p.isKeyClicked(MLV_KEYBOARD_z) || p.isKeyClicked(MLV_KEYBOARD_UP)) {
                flag = true;
                p.translate(geometry::Point16(0, -1));
            }
            if (p.isKeyClicked(MLV_KEYBOARD_d) || p.isKeyClicked(MLV_KEYBOARD_RIGHT)) {
                flag = true;
                p.translate(geometry::Point16(1, 0));
            }
            if (p.isKeyClicked(MLV_KEYBOARD_s) || p.isKeyClicked(MLV_KEYBOARD_DOWN)) {
                flag = true;
                p.translate(geometry::Point16(0, 1));
            }
            if (p.isKeyClicked(MLV_KEYBOARD_q) || p.isKeyClicked(MLV_KEYBOARD_LEFT)) {
                flag = true;
                p.translate(geometry::Point16(-1, 0));
            }
            
            // Rotating the shape
            if (p.isRightHeld() && !first) {
                flag = true;
                int16_t angle = (p.getRightPressedPoint().x - event.mousePos.x) / 5;
                p.rotate((angle - p.getCurrentRotation()) * Triangle::ANGLE_STEP);
                p.setCurrentRotation(angle);
            }
            if (p.isKeyClicked(MLV_KEYBOARD_a)) {
                flag = true;
                p.rotate(-Triangle::ANGLE_STEP);
            }
            if (p.isKeyClicked(MLV_KEYBOARD_e)) {
                flag = true;
                p.rotate(Triangle::ANGLE_STEP);
            }
            
            if (flag) { // Ensure only the shape above is modified
                first = true;
            }
        }
        
        return false;
    }
    
    
    void tangram::geometry::Shape::draw() const {
        std::for_each(this->polygons.begin(), this->polygons.end(), [](const Polygon &p) { p.draw(); });
    }
}
