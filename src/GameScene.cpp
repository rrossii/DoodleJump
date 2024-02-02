#include "GameScene.h"
#include "SpriteLocation.h"

GameScene::GameScene() {
    doodlePlayer = nullptr;
    prevFrameTime = std::chrono::steady_clock::now();
}

void GameScene::init() {
    doodlePlayer = new Doodle(
            SpriteLocation::doodleSpriteLocation,
            50, 0, 200);


    for (int i = 0; i < 15; i++) {
        int width = 320;
        int height = 200;
        double randX = rand() % width - 20;
        double randY = rand() % height - 20;

        Platform* platform = new Platform(randX, randY);

        platforms.emplace_back(platform);
    }
}

void GameScene::update(bool leftKeyIsPressed, bool rightKeyIsPressed) {
    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> delta = currentTime - prevFrameTime;
    double deltaTime = delta.count();
    prevFrameTime = currentTime;

    doodlePlayer->jump(deltaTime, leftKeyIsPressed, rightKeyIsPressed);

}

void GameScene::render() {
    doodlePlayer->render();

    for (auto p : platforms) {
        p->render();
    }
}

void GameScene::handleInput() {

}

void GameScene::cleanup() {
    delete doodlePlayer;

}

void GameScene::update() {

}
