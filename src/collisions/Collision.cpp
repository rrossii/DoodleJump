#include "Collision.h"

bool Collision::isColliding(Doodle *doodle, Platform *platform) {
    return
        doodle->getY() < platform->getY() + platform->getHeight() &&
        platform->getY() < doodle->getY() + doodle->getHeight() &&
        doodle->getX() < platform->getX() + platform->getWidth() &&
        platform->getX() < doodle->getX() + doodle->getWidth();
}
