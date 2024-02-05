#include "src/scenes/GameScene.h"

GameScene::GameScene(int width, int height) : Scene(width, height) {}

void GameScene::init() {
    doodlePlayer = new Doodle(
            SpriteLocation::doodleSpriteLocation,
            getWidth() / 2, getHeight() - 200, 0);

    spawnPlatforms();
}

void GameScene::update(bool firstJump, int deltaTime, bool leftKeyIsPressed, bool rightKeyIsPressed) {
    int screenWidth = getWidth();
    int screenHeight = getHeight();

    if (firstJump) {
        doodlePlayer->jump(screenHeight, screenWidth, deltaTime, leftKeyIsPressed, rightKeyIsPressed);
    }

    doodlePlayer->fall(deltaTime, screenWidth, leftKeyIsPressed, rightKeyIsPressed);

    for (auto platform : platforms) {
        if (Collision::isColliding(doodlePlayer, platform)) {
            doodlePlayer->jump(screenHeight, screenWidth, deltaTime,
                               leftKeyIsPressed, rightKeyIsPressed);
        }
    }
    cameraOffset();

    if (leftKeyIsPressed) {
        doodlePlayer->shoot();
    } if (doodlePlayer->hasUsedProjectile()) {
        if (!isDoodleDead()) {
            doodlePlayer->updateProjectilePosition();
        }
    }
}

void GameScene::render() {
    doodlePlayer->render();

    for (auto p : platforms) {
        p->render();
    }
}

void GameScene::cameraOffset() {
    int offset = getHeight() / 2;
    if (doodlePlayer->getY() < offset) {
        for (Platform* platform : platforms) {
            platform->setPosition(platform->getX(), platform->getY() + 1); // TODO: think about this parameter

            if (platform->getY() > getHeight()) {
                int randX = Randomizer::getRandomNumber(0, getWidth() - platform->getWidth());
                platform->setPosition(randX, 0);
            }
        }
    }
}

bool GameScene::isDoodleDead() {
    return doodlePlayer->getY() > getHeight();
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
    int spacingHorizontal = (platformWidth * 2) + 100;
    int numOfHorizontalLines = getHeight() / spacingVertical;
    int maxNumberOfPlatformsInOneLine = getWidth() / spacingHorizontal;
    int currentY = 0;

    for (int i = 0; i < numOfHorizontalLines; i++) {
        int numberOfPlatformsInOneLine = Randomizer::getRandomNumber(1, maxNumberOfPlatformsInOneLine);

        for (int j = 0; j < numberOfPlatformsInOneLine; j++) {
            int randX = Randomizer::getRandomNumber(0, getWidth() - platformWidth);
            int randY = Randomizer::getRandomNumber(currentY, currentY + spacingVertical);

            auto* platform = new Platform(randX, randY);
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

void GameScene::destroySprites() {
    destroySprite(doodlePlayer->getSprite());

    for (auto platform : platforms) {
        destroySprite(platform->getSprite());
    }
}
