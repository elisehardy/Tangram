#include "../include/Engine.hpp"
#include "../../shape/include/Triangle.hpp"
#include "../../shape/include/Parallelogram.hpp"
#include "../../shape/include/Square.hpp"
#include "../../shape/include/Polygon.hpp"
#include "../../shape/include/Point.hpp"
#include <MLV/MLV_all.h>


int main(int argc, char **argv) {
    //Tangram::Game::Engine game;

    Tangram::Shape::Point p1 = Tangram::Shape::Point(150,100);
    Tangram::Shape::Point p2 = Tangram::Shape::Point(50,50);
    Tangram::Shape::Point p3 = Tangram::Shape::Point(50,100);
    Tangram::Shape::Point p4 = Tangram::Shape::Point(150,50);

    Tangram::Shape::Point p5 = Tangram::Shape::Point(1700,1000);
    Tangram::Shape::Point p6 = Tangram::Shape::Point(700,1000);


    Tangram::Shape::Point pt = Tangram::Shape::Point(10,10);


    Tangram::Shape::Triangle t = Tangram::Shape::Triangle(p1,p2,p3, 0,  MLV_COLOR_RED);
    Tangram::Shape::Square q = Tangram::Shape::Square(p1,p3,p2, p4 ,0,  MLV_COLOR_RED);
    Tangram::Shape::Parallelogram p = Tangram::Shape::Parallelogram(p5,p6,p2, p1 ,0,  MLV_COLOR_RED);

    std::cout << "triangle" << std::endl;
    std::cout << t.getPoints()[0] <<std::endl;
    std::cout << t.getPoints()[1] <<std::endl;
    std::cout << t.getPoints()[2] <<std::endl;
    std::cout << t.center() << std::endl;
    std::cout << t.contains(400,1000) << std::endl;


    std::cout << t.getPoints()[0] <<std::endl;
    std::cout << t.getPoints()[1] <<std::endl;
    std::cout << t.getPoints()[2] <<std::endl;

    std::cout << "square" << std::endl;

    std::cout << q.getPoints()[0] <<std::endl;
    std::cout << q.getPoints()[1] <<std::endl;
    std::cout << q.getPoints()[2] <<std::endl;
    std::cout << q.getPoints()[3] <<std::endl;
    std::cout << q.contains(8,18) << std::endl;


    std::cout << p.getPoints()[0] <<std::endl;
    std::cout << p.getPoints()[1] <<std::endl;
    std::cout << p.getPoints()[2] <<std::endl;
    std::cout << p.getPoints()[3] <<std::endl;
    std::cout << p.contains(100,100) << std::endl;

    MLV_create_window( "beginner - 2 - shapes", "shapes", 640, 480 );
    t.draw();
    //q.draw();
    //p.draw();
    MLV_actualise_window();
    MLV_wait_mouse(nullptr, nullptr);
    t.move(pt);
    t.draw();
    //q.rotate(1);
    //q.draw();
    MLV_actualise_window();
    MLV_wait_seconds( 5 );
    MLV_free_window();

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
