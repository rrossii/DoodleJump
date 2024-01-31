#include "GameScene.h"

GameScene::GameScene() {
    doodlePlayer = nullptr;
}

void GameScene::init() {
    doodlePlayer = new Doodle();
}

void GameScene::update() {

    doodlePlayer->jump();
}

void GameScene::render() {
    doodlePlayer->render();
}

void GameScene::handleInput() {

}

void GameScene::cleanup() {
    delete doodlePlayer;
}
