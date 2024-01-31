#include "MainMenuScene.h"
#include <iostream>


MainMenuScene::MainMenuScene() {
    startGameButton = nullptr;
    exitGameButton = nullptr;
}

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

