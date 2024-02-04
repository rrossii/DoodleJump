#include "src/scenes/MainMenuScene.h"
#include <iostream>


MainMenuScene::MainMenuScene(int width, int height) : Scene(width, height) {}

void MainMenuScene::init() {
//    startGameButton = new UIElement();
//    exitGameButton = new UIElement();
}

void MainMenuScene::update() {

}

void MainMenuScene::render() {
//    startGameButton->render();
//    exitGameButton->render();
}

void MainMenuScene::handleInput() {

}

void MainMenuScene::cleanup() {
    delete startGameButton;
    delete exitGameButton;
}

void MainMenuScene::destroySprites() {

}

