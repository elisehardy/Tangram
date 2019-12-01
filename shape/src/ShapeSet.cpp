#include "../include/ShapeSet.hpp"

#include "../include/Triangle.hpp"
#include "../include/Square.hpp"


using namespace Shape;


ShapeSet::ShapeSet(Point offset) {
    Point ul = {0, 0}, ur = {L_TRIANGLE_H, 0}, bl = {0, L_TRIANGLE_H}, br = {L_TRIANGLE_H, L_TRIANGLE_H};
    Point rm = {L_TRIANGLE_H, M_TRIANGLE_S}, bm = {M_TRIANGLE_S, L_TRIANGLE_H};
    Point urm = {M_TRIANGLE_S + PARALLELOGRAM_WIDTH, PARALLELOGRAM_WIDTH};
    Point blm = {PARALLELOGRAM_WIDTH, M_TRIANGLE_S + PARALLELOGRAM_WIDTH};
    Point brm = {M_TRIANGLE_S + PARALLELOGRAM_WIDTH, M_TRIANGLE_S + PARALLELOGRAM_WIDTH};
    Point m = {M_TRIANGLE_S / 2, M_TRIANGLE_S / 2};
    
    auto *ltriangle1 = new Triangle(ul, ur, m, MLV_COLOR_RED);
    auto *ltriangle2 = new Triangle(ul, bl, m, MLV_COLOR_BROWN);
    auto *mtriangle1 = new Triangle(br, rm, bm, MLV_COLOR_CYAN);
    auto *striangle1 = new Triangle(m, urm, brm, MLV_COLOR_YELLOW);
    auto *striangle2 = new Triangle(bl, bm, blm, MLV_COLOR_ORANGE);
    auto *parallelogram = new Square(ur, rm, brm, urm, MLV_COLOR_GREEN);
    auto *square = new Square(m, blm, bm, brm, MLV_COLOR_WHITE);
    
    this->push_back(ltriangle1);
    this->push_back(ltriangle2);
    this->push_back(mtriangle1);
    this->push_back(striangle1);
    this->push_back(striangle2);
    this->push_back(parallelogram);
    this->push_back(square);
}


auto ShapeSet::operator==(const ShapeSet &other) const -> bool {
    std::vector<Point> s1, s2, tmp;
    
    for (Polygon *p: *this) {
        tmp = p->getPoints();
        s1.insert(s1.end(), tmp.begin(), tmp.end());
    }
    
    for (Polygon *p: other) {
        tmp = p->getPoints();
        s1.insert(s1.end(), tmp.begin(), tmp.end());
    }
    
    return std::is_permutation(s1.begin(), s1.end(), s2.begin());
}


void ShapeSet::draw() const {
    std::for_each(this->begin(), this->end(), [](const Polygon *p) { p->draw(); });
}


void ShapeSet::update(const Game::Event &event, Game::Engine &engine) {
    std::for_each(this->begin(), this->end(), [&event, &engine](Polygon *p) { p->update(event, engine); });
}
