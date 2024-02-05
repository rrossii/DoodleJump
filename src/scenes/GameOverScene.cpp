#include "GameOverScene.h"

GameOverScene::GameOverScene(int width, int height) : Scene(width, height) {}

void GameOverScene::init() {
    playAgainButton = new UIElement(SpriteLocation::getPlayAgainButtonSpriteLocation(),
                                    {getSceneWidth() / 2, getSceneHeight() / 2});
    scores = new UIElement(SpriteLocation::getScoresButtonSpriteLocation(),
                           {playAgainButton->getX(), playAgainButton->getY() + 100});
}


void GameOverScene::update() {

}

void GameOverScene::render() {
    UIManager::render(playAgainButton);
    UIManager::render(scores);
}

void GameOverScene::handleInput() {

}

void GameOverScene::cleanup() {

}

void GameOverScene::destroySprites() {

}

