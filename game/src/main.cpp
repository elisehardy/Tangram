#include "../include/Engine.hpp"
#include "../../shape/include/Triangle.hpp"
#include "../../shape/include/Parallelogram.hpp"
#include "../../shape/include/Square.hpp"
#include "../../shape/include/Polygon.hpp"
#include "../../shape/include/Point.hpp"


int main(int argc, char **argv) {
    //Tangram::Game::Engine game;

    Tangram::Shape::Point p1 = Tangram::Shape::Point(15,5);
    Tangram::Shape::Point p2 = Tangram::Shape::Point(5,5);
    Tangram::Shape::Point p3 = Tangram::Shape::Point(5,15);
    Tangram::Shape::Point p4 = Tangram::Shape::Point(15,15);


    Tangram::Shape::Triangle t = Tangram::Shape::Triangle(p1,p2,p3, 0,  MLV_COLOR_RED);
    Tangram::Shape::Square q = Tangram::Shape::Square(p1,p2,p3, p4 ,0,  MLV_COLOR_RED);
    Tangram::Shape::Parallelogram p = Tangram::Shape::Parallelogram(p1,p2,p3, p4 ,0,  MLV_COLOR_RED);

    std::cout << t.getPoints()[0] <<std::endl;
    std::cout << t.getPoints()[1] <<std::endl;
    std::cout << t.getPoints()[2] <<std::endl;
    std::cout << t.contains(4,10) << std::endl;


    std::cout << q.getPoints()[0] <<std::endl;
    std::cout << q.getPoints()[1] <<std::endl;
    std::cout << q.getPoints()[2] <<std::endl;
    std::cout << q.getPoints()[3] <<std::endl;
    std::cout << q.contains(8,18) << std::endl;


    std::cout << p.getPoints()[0] <<std::endl;
    std::cout << p.getPoints()[1] <<std::endl;
    std::cout << p.getPoints()[2] <<std::endl;
    std::cout << p.getPoints()[3] <<std::endl;
    std::cout << p.contains(10,10) << std::endl;





    // initialize the engine
    //game.init();

    // load the intro

    // main loop
   /* while (!game.over()) {
        game.handleEvents();
        game.update();
        game.draw();
    }

    // cleanup the engine
    game.cleanup();*/
    return 0;
}
