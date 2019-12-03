cmake_minimum_required(VERSION 2.8.8)
project(b'Tangram')

add_library(Tangram OBJECT
        shape/src/Triangle.cpp
        gui/src/Observer.cpp
        gui/src/Button.cpp
        shape/src/Point.cpp
        state/src/Play.cpp
        state/src/Edit.cpp
        state/src/Menu.cpp
        shape/src/Square.cpp
        game/src/Engine.cpp
        shape/src/ShapeSet.cpp
        shape/src/Polygon.cpp
        game/src/Event.cpp
        game/src/main.cpp
        shape/src/Vector.cpp
        )
target_compile_options(Tangram PRIVATE
        -g
        -O2
        -Wall
        -Wextra
        -Werror
        -Wfatal-errors
        -Weffc++
        -Wpointer-arith
        -std=c++17
        -Wno-unused-parameter
        -Wno-effc++
        )
target_include_directories(Tangram PRIVATE)
