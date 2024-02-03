#include "Enemy.h"

Enemy::Enemy(const std::filesystem::path &spriteLocation, double posX, double posY, bool isDead)
    : Actor(spriteLocation, posX, posY), dead(isDead) {}

