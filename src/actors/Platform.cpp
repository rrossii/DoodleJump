#include "src/actors/Platform.h"

Platform::Platform(int x, int y) : Actor(SpriteLocation::getPlatformSpriteLocation(), x, y) {

}

void Platform::addEnemyOnPlatform(Enemy *enemy) {
    hasEnemy = true;
    this->enemy = enemy;

}

bool Platform::hasEnemyOnPlatform() {
    return hasEnemy;
}

Enemy *Platform::getEnemy() {
    return enemy;
}

void Platform::deleteEnemyFromPlatform() {
    hasEnemy = false;
    enemy = nullptr;
}
