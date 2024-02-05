#include "src/scenes/GameScene.h"
#include <iostream>

const int passedPlatformsFrequencyToSpawnEnemy = 10;
int numberOfPassedPlatforms = 0;

GameScene::GameScene(int width, int height) : Scene(width, height) {}

void GameScene::init() {
    doodlePlayer = new Doodle(
            SpriteLocation::getDoodleSpriteLocation(),
            getSceneWidth() / 2, getSceneHeight() - 200, 0);

    spawnPlatforms();
}

void GameScene::update(bool firstJump, int deltaTime, bool leftKeyIsPressed, bool rightKeyIsPressed) {
    int screenWidth = getSceneWidth();
    int screenHeight = getSceneHeight();

    if (firstJump) {
        doodlePlayer->jump(screenHeight, screenWidth, deltaTime, leftKeyIsPressed, rightKeyIsPressed);
    }

    doodlePlayer->fall(deltaTime, screenWidth, leftKeyIsPressed, rightKeyIsPressed);

    for (auto platform: platforms) {
        if (Collision::isColliding(doodlePlayer, platform)) {
            doodlePlayer->jump(screenHeight, screenWidth, deltaTime,
                               leftKeyIsPressed, rightKeyIsPressed);
        }
    }
    cameraOffset();

    if (leftKeyIsPressed) {
        doodlePlayer->shoot();
    }
    if (doodlePlayer->hasUsedProjectile()) {
        if (!isDoodleDead()) {
            doodlePlayer->updateProjectilePosition();
        }
    }

    if (numberOfPassedPlatforms > 0 && numberOfPassedPlatforms % passedPlatformsFrequencyToSpawnEnemy == 0) {
        spawnEnemies();
    }
}

void GameScene::render() {
    doodlePlayer->render();

    for (auto p: platforms) {
        p->render();
    }
    if (enemy != nullptr) {
        enemy->render();
    }
}

void GameScene::cameraOffset() {
    int offset = getSceneHeight() / 2;
    if (doodlePlayer->getY() < offset) {
        for (Platform *platform: platforms) {
            platform->setPosition(platform->getX(), platform->getY() + 1); // TODO: think about this parameter
//            if (platform->hasEnemyOnPlatform()) {
//                platform->getEnemy()->setPosition(platform->getX(), platform->getY() + 1);
//                platform->deleteEnemyFromPlatform();
//            }

            if (platform->getY() > getSceneHeight()) {
                numberOfPassedPlatforms++;
            }

            // create "new" platforms
            if (platform->getY() > getSceneHeight()) {
                int randX = Randomizer::getRandomNumber(0, getSceneWidth() - platform->getWidth());
                platform->setPosition(randX, 0);
            }
        }
        if (enemy != nullptr) {
            enemy->setPosition(enemy->getX(), enemy->getY() + 1);
            if (enemy->getY() > getSceneHeight()) {
                enemy = nullptr;
            }
        }
    }
}

bool GameScene::isDoodleDead() {
    return doodlePlayer->getY() > getSceneHeight();
}

void GameScene::handleInput() {

}

void GameScene::update() {

}

void GameScene::spawnPlatforms() {
    auto *basicPlatform = new Platform(0, 0);
    int platformHeight = basicPlatform->getHeight();
    int platformWidth = basicPlatform->getWidth();
    int spacingVertical = platformHeight + 30;
    int spacingHorizontal = (platformWidth * 2) + 100;
    int numOfHorizontalLines = getSceneHeight() / spacingVertical;
    int maxNumberOfPlatformsInOneLine = getSceneWidth() / spacingHorizontal;
    int currentY = 0;

    for (int i = 0; i < numOfHorizontalLines; i++) {
        int numberOfPlatformsInOneLine = Randomizer::getRandomNumber(1, maxNumberOfPlatformsInOneLine);

        for (int j = 0; j < numberOfPlatformsInOneLine; j++) {
            int randX = Randomizer::getRandomNumber(0, getSceneWidth() - platformWidth);
            int randY = Randomizer::getRandomNumber(currentY, currentY + spacingVertical);

            auto *platform = new Platform(randX, randY);
            platforms.emplace_back(platform);
        }
        currentY += spacingVertical;
    }
}

void GameScene::spawnEnemies() {
    int overallNumberOfPlatforms = platforms.size();
    int indexOfEnemyPlatform = Randomizer::getRandomNumber(0, overallNumberOfPlatforms - 1);
    auto *enemyPlatform = platforms[indexOfEnemyPlatform];

    enemy = new Enemy(SpriteLocation::getButterflyEnemySpriteLocation(),
                            enemyPlatform->getX() + enemyPlatform->getWidth() / 2,
                            enemyPlatform->getY() + 10,
                            false);

//    enemyPlatform->addEnemyOnPlatform(enemy);
}

void GameScene::cleanup() {
    delete doodlePlayer;

    for (auto platform: platforms) {
        delete platform;
    }
}

void GameScene::destroySprites() {
    destroySprite(doodlePlayer->getSprite());

    for (auto platform: platforms) {
        destroySprite(platform->getSprite());
    }
}
