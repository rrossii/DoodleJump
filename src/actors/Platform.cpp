#include "src/actors/Platform.h"

Platform::Platform(int x, int y) : Actor(SpriteLocation::getPlatformSpriteLocation(), x, y) {

}

Enemy* Platform::getEnemy() {
    return enemy;
}

void Platform::setEnemy(Enemy* enemy) {
    this->enemy = enemy;
}

void Platform::removeEnemy() {
    enemy = nullptr;
}

bool Platform::hasEnemy() {
    return enemy != nullptr;
}
