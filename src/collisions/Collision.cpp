#include "Collision.h"

bool Collision::isColliding(Doodle *doodle, Platform *platform) {
    return
        doodle->getY() + doodle->getHeight() <= platform->getY() + platform->getHeight() &&
        doodle->getY() + doodle->getHeight() >= platform->getY() &&
        doodle->getX() <= platform->getX() + platform->getWidth() &&
        doodle->getX() >= platform->getX() - doodle->getWidth();

}

bool Collision::doodleDieFromEnemy(Doodle *doodle, Enemy *enemy) {
    return
        abs(doodle->getX() - enemy->getX()) < enemy->getWidth() &&
        abs(doodle->getY() - enemy->getY()) < enemy->getHeight() &&
        doodle->getY() >= enemy->getY();
}

bool Collision::doodleKillEnemy(Doodle *doodle, Enemy *enemy) {
    return
        abs(doodle->getX() - enemy->getX()) < enemy->getWidth() &&
        abs(doodle->getY() - enemy->getY()) < enemy->getHeight() &&
        doodle->getY() <= enemy->getY();
}
