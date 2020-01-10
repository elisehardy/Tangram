#include <algorithm>
#include <regex>
#include <ostream>

#include <tangram/geometry/Polygon.hpp>


namespace tangram::geometry {
    
    Polygon::Polygon(MLV_Color t_color) :
        color(t_color) {
    }
    
    
    Polygon Polygon::custom(const std::vector<Triangle> &triangles, MLV_Color color) {
        Polygon p = Polygon(color);
        p.add(triangles);
        return p;
    }
    
    
    Polygon Polygon::smallTriangle(const Point16 &offset, MLV_Color color) {
        return custom({ Triangle(offset) }, color);
    }
    
    
    Polygon Polygon::mediumTriangle(const Point16 &offset, MLV_Color color) {
        Triangle t1(offset);
        return custom(
            {
                t1.rotate(135, offset).translate(Triangle::HEIGHT, Triangle::HEIGHT),
                t1.rotate(225, offset).translate(Triangle::HEIGHT, Triangle::HEIGHT)
            },
            color
        );
    }
    
    
    Polygon Polygon::largeTriangle(const Point16 &offset, MLV_Color color) {
        Triangle t1(offset);
        return custom(
            {
                t1,
                t1.rotate(180, offset).translate(Triangle::SIDE, Triangle::SIDE),
                t1.translate(Triangle::SIDE, 0),
                t1.translate(0, Triangle::SIDE),
            },
            color
        );
    }
    
    
    Polygon Polygon::parallelogram(const Point16 &offset, MLV_Color color) {
        Triangle t1(offset);
        return custom(
            {
                t1.rotate(225, offset).translate(Triangle::HEIGHT + 1, Triangle::HEIGHT + 1),
                t1.rotate(45, offset).translate(Triangle::HYPOTENUSE, 0)
            },
            color
        );
    }
    
    
    Polygon Polygon::square(const Point16 &offset, MLV_Color color) {
        Triangle t1(offset);
        return custom(
            { t1, t1.rotate(180, offset).translate(Triangle::SIDE, Triangle::SIDE) },
            color
        );
    }
    
    
    Polygon &Polygon::translate(const Vector16 &v) {
        std::for_each(
            this->triangles.begin(), this->triangles.end(),
            [&](Triangle &t) { t = t.translate(v); }
        );
        
        this->buttons[MLV_BUTTON_LEFT].pressedPoint = this->buttons[MLV_BUTTON_LEFT].pressedPoint.translate(v);
        this->center = this->center.translate(v);
        return *this;
    }
    
    
    Polygon &Polygon::translate(int16_t x, int16_t y) {
        return this->translate({ x, y });
    }
    
    
    Polygon &Polygon::scale(const VectorD &v) {
        std::for_each(
            this->triangles.begin(), this->triangles.end(),
            [&](Triangle &t) { t = t.scale(v); }
        );
        
        this->buttons[MLV_BUTTON_LEFT].pressedPoint = Point16 (this->buttons[MLV_BUTTON_LEFT].pressedPoint * v);
        this->center = this->center * v;
        return *this;
    }
    
    
    Polygon &Polygon::scale(double x, double y) {
        return this->scale({ x, y });
    }
    
    
    Polygon &Polygon::scale(double factor) {
        return this->scale({ factor, factor });
    }
    
    
    Polygon &Polygon::rotate(int16_t n) {
        this->angle = (this->angle + n) % 360;
        return *this;
    }
    
    
    std::vector<Point16> Polygon::getPoints() const {
        std::vector<Point16> points = {};
        
        for (const Triangle &t: this->triangles) {
            auto trianglePoints = t.rotate(this->angle, this->center).getPoints();
            std::for_each(
                trianglePoints.begin(), trianglePoints.end(),
                [&points](const Point16 &p) { points.emplace_back(p); }
            );
        }
        
        return points;
    }
    
    
    int16_t Polygon::getCurrentRotation() const {
        return currentRotation;
    }
    
    
    void Polygon::setCurrentRotation(int16_t currentRotation) {
        Polygon::currentRotation = currentRotation;
    }
    
    
    void Polygon::setColor(MLV_Color color) {
        this->color = color;
    }
    
    
    bool Polygon::contains(const Point16 &p) const {
        return std::any_of(
            this->triangles.begin(), this->triangles.end(),
            [&p, this](const Triangle &t) { return t.rotate(this->angle, this->center).contains(p); }
        );
    }
    
    
    std::ostream &operator<<(std::ostream &os, const Polygon &p) {
        os << "{" << std::endl;
        for (const Triangle &t: p.triangles) {
            os << "    " << t << std::endl;
        }
        os << "}" << std::endl;
        return os;
    }
    
    
    void Polygon::add(const Triangle &t) {
        this->triangles.push_back(t);
        this->center = Point16::center(this->getPoints());
    }
    
    
    void Polygon::add(const std::vector<Triangle> &triangles) {
        std::for_each(triangles.begin(), triangles.end(), [this](const Triangle &t) { this->add(t); });
    }
    
    
    void Polygon::update(const game::Event &event, game::Engine &engine) {
        this->hovered = this->contains(event.mousePos);
        
        game::Updatable::update(event, engine);
        
        if (this->isRightPressed()) {
            this->currentRotation = 0;
        }
    }
    
    
    void Polygon::draw() const {
        uint8_t r, g, b, a;
        MLV_Color color;
        
        color = this->color;
        
        if (this->isLeftHeld() || this->isRightHeld()) {
            MLV_convert_color_to_rgba(this->color, &r, &g, &b, &a);
            color = MLV_rgba(uint8_t(r * 0.60), uint8_t(g * 0.60), uint8_t(b * 0.60), a);
        }
        else if (this->hovered) {
            MLV_convert_color_to_rgba(this->color, &r, &g, &b, &a);
            color = MLV_rgba(uint8_t(r * 0.80), uint8_t(g * 0.80), uint8_t(b * 0.80), a);
        }
        
        std::for_each(
            this->triangles.begin(), this->triangles.end(),
            [this, color](const Triangle &t) { t.rotate(this->angle, this->center).draw(color); }
        );
    }
}
