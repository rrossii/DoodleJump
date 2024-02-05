cmake_minimum_required(VERSION 3.27)
project(2022_win64)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".dll")

add_subdirectory(Framework)

include_directories(${PROJECT_SOURCE_DIR})

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
        src/utils/Randomizer.cpp
        src/ui/UIManager.cpp
        src/scenes/GameOverScene.cpp

        src/utils/Dimension.h
        src/utils/Position.h
)

find_library(Framework)

add_link_options(-static -static-libgcc -static-libstdc++)

target_link_libraries(doodleJump Framework)

