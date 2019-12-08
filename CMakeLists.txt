cmake_minimum_required(VERSION 3.15)
project(b'Tangram')

add_library(Tangram OBJECT
        geometry/src/Triangle.cpp
        gui/src/Observer.cpp
        gui/src/Button.cpp
        geometry/src/Point.cpp
        state/src/Play.cpp
        state/src/Edit.cpp
        state/src/Menu.cpp
        game/src/Engine.cpp
        geometry/src/Shape.cpp
        game/src/Event.cpp
        game/src/main.cpp
        geometry/src/Polygon.cpp geometry/src/Shape.cpp geometry/include/Shape.hpp)
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
