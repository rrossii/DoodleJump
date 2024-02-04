#include "Enemy.h"

Enemy::Enemy(const std::filesystem::path &spriteLocation, int posX, int posY, bool isDead)
    : Actor(spriteLocation, posX, posY), dead(isDead) {}

