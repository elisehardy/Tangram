cmake_minimum_required(VERSION 3.15)
project(b'Tangram')

add_library(Tangram OBJECT
        geometry/src/ParserException.cpp
        geometry/src/Triangle.cpp
        geometry/src/Parser.cpp
        geometry/src/Polygon.cpp
        geometry/src/Shape.cpp
        gui/src/Button.cpp
        state/src/Play.cpp
        state/src/Edit.cpp
        state/src/Menu.cpp
        state/src/Save.cpp
        state/src/Load.cpp
        game/src/Engine.cpp
        game/src/Event.cpp
        game/src/main.cpp

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
