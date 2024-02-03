#include "src/actors/Doodle.h"
#include "src/collisions/Collision.h"

constexpr int GRAVITY = 1000;
constexpr int GROUND_LEVEL = 0;
double dy = 0;


Doodle::Doodle(const std::filesystem::path &spriteLocation, double posX, double posY, double velocityY)
        : Actor(spriteLocation, posX, posY), velocityY(velocityY) {}


void Doodle::jump(int screenHeight, int screenWidth,
                  double deltaTime, bool isLeftKeyPressed, bool isRightKeyPressed) {

    displacementByX(screenWidth, isLeftKeyPressed, isRightKeyPressed);

    dy -= 0.5;
//    positionY -= dy;
}

void Doodle::displacementByX(int screenWidth, bool isLeftKeyPressed, bool isRightKeyPressed) {
    if (isLeftKeyPressed) {
        positionX -= 1;
    }
    if (isRightKeyPressed) {
        positionX += 1;
    }

    if (positionX >= screenWidth) {
        positionX = 0;
    } else if (positionX < 0) {
        positionX = screenWidth;
    }
}

void Doodle::fall(int screenWidth, bool isLeftKeyPressed, bool isRightKeyPressed) {
    dy += 0.08;
    positionY += dy;
    displacementByX(screenWidth, isLeftKeyPressed, isRightKeyPressed);
}

void Doodle::shoot(Projectile *projectile) {

}

//void Doodle::jump(double deltaTime) {
//    isJumping = true;
//
//    velocityY -= GRAVITY * deltaTime;
//    positionY += velocityY * deltaTime;
//
//    if (positionY <= GROUND_LEVEL) {
//        positionY = GROUND_LEVEL;
//        velocityY = 200;
//        isJumping = false;
//    } else if (positionY >= 100) { // bottom of the screen
//        positionY = 100;
//    }
//}
