#include "Collision.h"

bool Collision::isColliding(Doodle *doodle, Platform *platform) {
    return
        doodle->getY() + doodle->getHeight() <= platform->getY() + platform->getHeight() &&
        doodle->getY() + doodle->getHeight() >= platform->getY() &&
        doodle->getX() <= platform->getX() + platform->getWidth() &&
        doodle->getX() >= platform->getX() - doodle->getWidth();

}
