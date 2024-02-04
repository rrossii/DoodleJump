#include "Projectile.h"

Projectile::Projectile(const std::filesystem::path &spriteLocation, double posX, double posY)
    : Actor(spriteLocation, posX, posY) {}
