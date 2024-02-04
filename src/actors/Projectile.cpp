#include "Projectile.h"

Projectile::Projectile(const std::filesystem::path &spriteLocation, int posX, int posY)
    : Actor(spriteLocation, posX, posY) {}
