#include <MLV/MLV_all.h>
#include <iostream>
#include "../shape/include/Point.hpp"
#include "../shape/include/Triangle.hpp"


using namespace Tangram::Shape;


int main(int argc, char **argv) {
    Triangle t = Triangle(Point({10, 10}), 0, MEDIUM, MLV_COLOR_RED);
    Point a = {-4, 3};
    
    for (Point &p: t.getPoints()) {
        std::cout << p << std::endl;
    }
    
    return 0;
}
