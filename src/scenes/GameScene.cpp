#include "src/scenes/GameScene.h"
#include "src/utils/SpriteLocation.h"
#include "src/collisions/Collision.h"
#include <iostream>

GameScene::GameScene(int width, int height) : Scene(width, height) {}

void GameScene::init() {
    doodlePlayer = new Doodle(
            SpriteLocation::doodleSpriteLocation,
            50, 0, 200);

    spawnPlatforms();

    prevFrameTime = std::chrono::steady_clock::now();
}

void GameScene::update(bool leftKeyIsPressed, bool rightKeyIsPressed) {
    int screenWidth = getWidth();
    int screenHeight = getHeight();

    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> delta = currentTime - prevFrameTime;
    double deltaTime = delta.count();
    prevFrameTime = currentTime;

    doodlePlayer->fall(screenWidth, leftKeyIsPressed, rightKeyIsPressed);

    for (auto platform : platforms) {
        if (Collision::isColliding(doodlePlayer, platform)) {
            doodlePlayer->jump(screenHeight, screenWidth, deltaTime,
                               leftKeyIsPressed, rightKeyIsPressed);
        }
    }
}

void GameScene::render() {
    doodlePlayer->render();

    for (auto p : platforms) {
        p->render();
    }
}

void GameScene::handleInput() {

}

void GameScene::update() {

}

void GameScene::spawnPlatforms() {
    for (int i = 0; i < 15; i++) {
        double randX = rand() % getWidth() - 20;
        double randY = rand() % getHeight() - 20;

        Platform* platform = new Platform(randX, randY);

        platforms.emplace_back(platform);
    }
}

void GameScene::spawnEnemies() {

}

void GameScene::cleanup() {
    delete doodlePlayer;

    for (auto platform : platforms) {
        delete platform;
    }
}
