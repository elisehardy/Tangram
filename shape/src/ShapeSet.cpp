#include "../include/ShapeSet.hpp"


using namespace Shape;


bool ShapeSet::operator==(const ShapeSet &other) const {
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
