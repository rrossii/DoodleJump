cmake_minimum_required(VERSION 3.27)
project(2022_win64)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".dll")

include_directories(${PROJECT_SOURCE_DIR})
link_directories(${CMAKE_SOURCE_DIR})

add_definitions(-D_WINDOWS)

add_executable(doodleJump
        src/game.cpp
        src/actors/Actor.cpp
        src/scenes/MainMenuScene.cpp
        src/ui/UIElement.cpp
        src/scenes/GameScene.cpp
        src/actors/Doodle.cpp
        src/actors/Platform.cpp
        src/utils/SpriteLocation.cpp
        src/collisions/Collision.cpp
        src/actors/Enemy.cpp
        src/actors/Projectile.cpp
        src/scenes/Scene.cpp
)

find_library(
        FrameworkRelease_x64
        PATHS
        ${CMAKE_SOURCE_DIR}
)

add_link_options(-static -static-libgcc -static-libstdc++)

target_link_libraries(doodleJump FrameworkRelease_x64)

