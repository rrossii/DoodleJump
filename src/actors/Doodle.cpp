#include "src/actors/Doodle.h"

constexpr double GRAVITY = 0.1;

int sceneWidth, sceneHeight;


Doodle::Doodle(const std::filesystem::path &spriteLocation, int posX, int posY, double velocityY)
        : Actor(spriteLocation, posX, posY), velocityY(velocityY) {}


void Doodle::jump(int screenHeight, int screenWidth,
                  bool isLeftKeyPressed, bool isRightKeyPressed) {
    sceneWidth = screenWidth;
    sceneHeight = screenHeight;

    displacementByX(isLeftKeyPressed, isRightKeyPressed);

    velocityY -= 5;
    if (velocityY < -5) {
        velocityY = -5;
    }
    if (position.y < 0) {
        velocityY = 0;
    }
}

void Doodle::displacementByX(bool isLeftKeyPressed, bool isRightKeyPressed) {
    if (isLeftKeyPressed) {
        position.x -= 3;
    }
    if (isRightKeyPressed) {
        position.x += 3;
    }

    if (position.x >= sceneWidth) {
        position.x = 0;
    } else if (position.x < 0) {
        position.x = sceneWidth;
    }
}

void Doodle::fall(bool isLeftKeyPressed, bool isRightKeyPressed) {
    position.y += velocityY;
    velocityY += GRAVITY;

    displacementByX(isLeftKeyPressed, isRightKeyPressed);
}

void Doodle::shoot() {
    projectile = new Projectile(SpriteLocation::getProjectileSpriteLocation(),
                                this->position.x + this->getWidth() / 2, this->position.y - this->getHeight() / 2);
    projectile->render();
}

bool Doodle::hasUsedProjectile() {
    return projectile != nullptr;
}

void Doodle::updateProjectilePosition() {
    if (projectile) {
        projectile->setY(projectile->getY() + projectile->getSpeed());
        projectile->render();
    }
}

void Doodle::die() {
    while (position.y < sceneHeight) {
        position.y += 1;
        render();
    }
}
