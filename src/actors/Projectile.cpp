#include "Projectile.h"

Projectile::Projectile(const std::filesystem::path &spriteLocation, int posX, int posY)
    : Actor(spriteLocation, posX, posY) {}

int Projectile::getSpeed() {
    return SPEED;
}

void Projectile::setY(int y) {
    position.y = y;
}

void Projectile::update() {
    position.y += SPEED;
}
