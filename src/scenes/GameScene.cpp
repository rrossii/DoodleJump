#include "src/scenes/GameScene.h"
#include "src/utils/SpriteLocation.h"
#include "src/collisions/Collision.h"
#include <iostream>
#include <random>

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
    auto* basicPlatform = new Platform(0, 0);
    int platformHeight = basicPlatform->getHeight();
    int platformWidth = basicPlatform->getWidth();
    int spacingVertical = platformHeight + 30;
    int spacingHorizontal = platformWidth * 2;
    int numOfHorizontalLines = getHeight() / spacingVertical;
    int maxNumberOfPlatformsInOneLine = getWidth() / spacingHorizontal;
    int currentY = 0;

    for (int i = 0; i < numOfHorizontalLines; i++) {
        int numberOfPlatformsInOneLine = rand() % maxNumberOfPlatformsInOneLine;

        for (int j = 0; j < numberOfPlatformsInOneLine; j++) {
            std::random_device random_device;
            std::mt19937 generator(random_device());

            std::uniform_int_distribution<> distributionX(0, getWidth() - platformWidth);
            std::uniform_int_distribution<> distributionY(currentY, currentY + spacingVertical);

            double randX = distributionX(generator);
            double randY = distributionY(generator);

            Platform* platform = new Platform(randX, randY);

            platforms.emplace_back(platform);
        }
        currentY += spacingVertical;
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
