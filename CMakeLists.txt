CMAKE_MINIMUM_REQUIRED(VERSION 3.7)

PROJECT(Tangram)

SET(CMAKE_CXX_COMPILER /usr/bin/clang++)
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(MLV REQUIRED IMPORTED_TARGET MLV)

SET(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/)
INCLUDE_DIRECTORIES(
    ${INCLUDE_DIR}
)

FILE(GLOB_RECURSE SOURCE_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
FILE(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/include/*.hpp)

SET(TARGET_NAME tangram)
ADD_EXECUTABLE(${TARGET_NAME} ${SOURCE_FILES} ${HEADER_FILES})
TARGET_LINK_LIBRARIES(${TARGET_NAME} PUBLIC PkgConfig::MLV)

TARGET_COMPILE_OPTIONS(
    ${TARGET_NAME} PRIVATE
    -g
    -O2
    -Werror
    -Weverything
    -Wfatal-errors
    -std=c++17
)

# Disable some warnings
IF (CLANG_VERSION_MAJOR GREATER_EQUAL 10)
    TARGET_COMPILE_OPTIONS(
        ${TARGET_NAME} PRIVATE
        -Wno-unused-parameter
        -Wno-effc++
        -Wno-shadow
        -Wno-c++98-compat
        -Wno-padded
        -Wno-weak-vtables
        -Wno-global-constructors
        -Wno-exit-time-destructors
        -Wno-unused-template
        -Wno-c++11-narrowing
    )
ELSE ()
    TARGET_COMPILE_OPTIONS(
        ${TARGET_NAME} PRIVATE
        -Wno-unused-parameter
        -Wno-effc++
        -Wno-shadow
        -Wno-c++98-compat
        -Wno-padded
        -Wno-weak-vtables
        -Wno-global-constructors
        -Wno-exit-time-destructors
        -Wno-unused-template
        -Wno-c++11-narrowing
    )
ENDIF ()
