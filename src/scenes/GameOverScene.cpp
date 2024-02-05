#include "GameOverScene.h"

GameOverScene::GameOverScene(int width, int height) : Scene(width, height) {}

void GameOverScene::init() {
    playAgainButton = new UIElement(SpriteLocation::getPlayAgainButtonSpriteLocation(),
                                    {getSceneWidth() / 3, getSceneHeight() / 3});
}


void GameOverScene::update() {

}

void GameOverScene::render() {
    playAgainButton->render();
}

void GameOverScene::handleInput() {

}

void GameOverScene::cleanup() {

}

void GameOverScene::destroySprites() {

}

