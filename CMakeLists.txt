# Here for CLion's autocompletion
CMAKE_MINIMUM_REQUIRED(VERSION 3.13)
PROJECT(dummy)

SET(CMAKE_CXX_STANDARD 17)
INCLUDE_DIRECTORIES(include)



add_executable(tangram  src/main.cpp)
