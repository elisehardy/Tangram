#include <algorithm>
#include <regex>

#include "../include/Polygon.hpp"


using namespace tangram::geometry;


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
    
    this->pressedPoint = this->pressedPoint.translate(v);
    this->center = this->center.translate(v);
    return *this;
}


Polygon &Polygon::translate(int16_t x, int16_t y) {
    return this->translate({ x, y });
}


Polygon &Polygon::rotate(int16_t n) {
    this->angle = (this->angle + n) % 360;
    return *this;
}


std::vector<Point16> Polygon::getPoints() const {
    std::vector<Point16> points = {};
    
    for (const Triangle &t: this->triangles) {
        auto trianglePoints = t.getPoints();
        std::for_each(
                trianglePoints.begin(), trianglePoints.end(),
                [&points](const Point16 &p) { points.push_back(Point16(p)); }
        );
    }
    
    return points;
}


bool Polygon::contains(const Point16 &p) const {
    return std::any_of(
            this->triangles.begin(), this->triangles.end(),
            [&p, this](const Triangle &t) { return t.rotate(this->angle, this->center).contains(p); }
    );
}


void Polygon::save(const Polygon &p, MLV_Color color, bool shadow) const {
}


void Polygon::add(const Triangle &t) {
    this->triangles.push_back(t);
    this->center = center = Point16::center(this->getPoints());
}


void Polygon::add(const std::vector<Triangle> &triangles) {
    std::for_each(triangles.begin(), triangles.end(), [this](const Triangle &t) { this->add(t); });
}


void Polygon::update(const game::Event &event, game::Engine &engine) {
    bool leftClick = event.type == MLV_MOUSE_BUTTON && event.mouseButton == MLV_BUTTON_LEFT;
    bool rightClick = event.type == MLV_MOUSE_BUTTON && event.mouseButton == MLV_BUTTON_RIGHT;
    
    this->hovered = this->contains(event.mousePos);
    
    if (this->hovered && leftClick && event.state == MLV_PRESSED) {  // Left button pressed
        this->pressedPoint = Point16(event.mousePos);
        this->lpressed = true;
    }
    else if (this->lpressed && leftClick && event.state == MLV_RELEASED) {  // Left button released
        this->lpressed = false;
    }
    
    if (this->lpressed) { // Moving the Shape
        this->translate(event.mousePos - this->pressedPoint);
    }
    
    if (this->hovered && rightClick && event.state == MLV_PRESSED) {  // Right button pressed
        this->pressedPoint = Point16(event.mousePos);
        this->currentRotation = 0;
        this->rpressed = true;
    }
    else if (this->rpressed && rightClick && event.state == MLV_RELEASED) { // Left click released
        this->rpressed = false;
    }
    
    if (this->rpressed) { // Rotating the shape
        int16_t angle = (pressedPoint.x - event.mousePos.x) / 15;
        this->rotate((angle - this->currentRotation) * Triangle::ANGLE_STEP);
        this->currentRotation = angle;
    }
}


void Polygon::draw() const {
    uint8_t r, g, b, a;
    MLV_Color color;
    
    color = this->color;
    
    if (this->lpressed || this->rpressed) {
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


void Polygon::shadow(MLV_Color color) const {
    std::vector<Point16> hull = Point16::convexHull(this->getPoints());
    long size = hull.size();
    long i;
    
    for (i = 0; i < size - 1; i++) {
        MLV_draw_line(hull[i].x, hull[i].y, hull[i + 1].x, hull[i + 1].y, color);
    }
    MLV_draw_line(hull[0].x, hull[0].y, hull[i].x, hull[i].y, color);
}
