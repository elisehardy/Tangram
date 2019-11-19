#include <MLV/MLV_all.h>
#include <iostream>
#include "../shape/include/Point.hpp"
int main(int argc, char **argv) {
    Tangram::Shape::Point a = {1, 2};
    std::cout << a.first << " " << a.second << std::endl;
    return 0;
}
