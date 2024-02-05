#include "src/actors/Doodle.h"

constexpr double GRAVITY = 0.1;

int sceneWidth, sceneHeight;


Doodle::Doodle(const std::filesystem::path &spriteLocation, int posX, int posY, double velocityY)
        : Actor(spriteLocation, posX, posY), velocityY(velocityY) {}


void Doodle::jump(int screenHeight, int screenWidth,
                  double deltaTime, bool isLeftKeyPressed, bool isRightKeyPressed) {

    displacementByX(screenWidth, isLeftKeyPressed, isRightKeyPressed);

    velocityY -= 5;
    if (velocityY < -5) {
        velocityY = -5;
    }
    if (position.y < 0) {
        velocityY = 0;
    }
}

void Doodle::displacementByX(int screenWidth, bool isLeftKeyPressed, bool isRightKeyPressed) {
    if (isLeftKeyPressed) {
        position.x -= 3;
    }
    if (isRightKeyPressed) {
        position.x += 3;
    }

    if (position.x >= screenWidth) {
        position.x = 0;
    } else if (position.x < 0) {
        position.x = screenWidth;
    }
}

void Doodle::fall(double deltaTime, int screenWidth, bool isLeftKeyPressed, bool isRightKeyPressed) {
    position.y += velocityY;
    velocityY += GRAVITY;

    displacementByX(screenWidth, isLeftKeyPressed, isRightKeyPressed);
}

void Doodle::shoot() {
    projectile = new Projectile(SpriteLocation::projectileSpriteLocation,
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
