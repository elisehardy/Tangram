cmake_minimum_required(VERSION 3.15)
project(b'Tangram')

SET(CMAKE_CXX_COMPILER "/usr/bin/clang++")

add_library(Tangram OBJECT
        /home/qcoumes/git/Tangram/geometry/src/ParserException.cpp
        /home/qcoumes/git/Tangram/game/src/Engine.cpp
        /home/qcoumes/git/Tangram/gui/src/Button.cpp
        /home/qcoumes/git/Tangram/geometry/src/Shape.cpp
        /home/qcoumes/git/Tangram/geometry/src/Polygon.cpp
        /home/qcoumes/git/Tangram/state/src/Menu.cpp
        /home/qcoumes/git/Tangram/geometry/src/Parser.cpp
        /home/qcoumes/git/Tangram/game/src/main.cpp
        /home/qcoumes/git/Tangram/state/src/Edit.cpp
        /home/qcoumes/git/Tangram/geometry/src/Triangle.cpp
        /home/qcoumes/git/Tangram/game/src/Event.cpp
        /home/qcoumes/git/Tangram/state/src/Play.cpp
        )
target_compile_options(Tangram PRIVATE
        -g
        -O2
        -Werror
        -Weverything
        -Wfatal-errors
        -std=c++17
        -Wno-unused-parameter
        -Wno-effc++
        -Wno-shadow
        -Wno-c++98-compat
        -Wno-sign-conversion
        -Wno-padded
        -Wno-global-constructors
        -Wno-weak-vtables
        -Wno-delete-non-abstract-non-virtual-dtor
        -Wno-exit-time-destructors
        -Wno-c++11-narrowing
        -Wno-unneeded-internal-declaration
        -Wno-float-conversion
        -Wno-unused-template
        )
target_include_directories(Tangram PRIVATE
        )
