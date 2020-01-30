CMAKE_MINIMUM_REQUIRED(VERSION 3.7)


PROJECT(Tangram)


SET(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/)
SET(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src/)


FIND_PACKAGE(PkgConfig REQUIRED)
PKG_CHECK_MODULES(MLV REQUIRED IMPORTED_TARGET MLV)


INCLUDE_DIRECTORIES(
    ${INCLUDE_DIR}
)

FILE(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}*.cpp)
FILE(GLOB_RECURSE HEADER_FILES ${INCLUDE_DIR}*.hpp)


SET(TARGET_NAME tangram)
ADD_EXECUTABLE(${TARGET_NAME} ${SOURCE_FILES} ${HEADER_FILES})
TARGET_LINK_LIBRARIES(${TARGET_NAME} PUBLIC PkgConfig::MLV stdc++fs)


MESSAGE("Using compiler ${CMAKE_CXX_COMPILER_ID}")
IF (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
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
        -Wno-deprecated
    )
ELSEIF (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    TARGET_COMPILE_OPTIONS(
        ${TARGET_NAME} PRIVATE
        -g
        -O2
        -Werror
        -Wall
        -Wextra
        -Wfatal-errors
        -std=c++17
    )
    
    # Disable some warnings
    TARGET_COMPILE_OPTIONS(
        ${TARGET_NAME} PRIVATE
        -Wno-unused-parameter
        -Wno-sign-compare
    )
ENDIF ()


