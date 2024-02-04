#include "GameOverScene.h"

GameOverScene::GameOverScene(int width, int height) : Scene(width, height) {}

void GameOverScene::init() {
    playAgainButton = new UIElement(SpriteLocation::playAgainButtonSpriteLocation,
                                    {getWidth() / 2, getHeight() / 2});
    scores = new UIElement(SpriteLocation::scoresButtonSpriteLocation,
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

