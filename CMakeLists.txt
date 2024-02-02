cmake_minimum_required(VERSION 3.27)
project(2022_win64)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".dll")

include_directories(${PROJECT_SOURCE_DIR})
link_directories(${CMAKE_SOURCE_DIR})

add_definitions(-D_WINDOWS)

add_executable(doodleJump
        src/game.cpp
        src/Actor.cpp
        src/MainMenuScene.cpp
        src/UIElement.cpp
        src/GameScene.cpp
        src/Doodle.cpp
        src/Platform.cpp
        src/Platform.h
        src/SpriteLocation.cpp
        src/SpriteLocation.h
        src/Collision.cpp
        src/Collision.h
)

find_library(
        FrameworkRelease_x64
        PATHS
        ${CMAKE_SOURCE_DIR}
)

add_link_options(-static -static-libgcc -static-libstdc++)

target_link_libraries(doodleJump FrameworkRelease_x64)

