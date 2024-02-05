#include "Enemy.h"

Enemy::Enemy(const std::filesystem::path &spriteLocation, int posX, int posY)
    : Actor(spriteLocation, posX, posY) {}

void Enemy::die(int sceneHeight) {
    while (position.y < sceneHeight) {
        position.y += 1;
        render();
    }
}

