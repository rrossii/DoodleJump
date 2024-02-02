#include "Doodle.h"
#include "Framework.h"

constexpr int GRAVITY = 1000;
constexpr int GROUND_LEVEL = 0;
double dy = 0;


Doodle::Doodle(const std::filesystem::path &spriteLocation, double posX, double posY, double velocityY)
        : Actor(spriteLocation, posX, posY), velocityY(velocityY) {}


void Doodle::jump(double deltaTime, bool isLeftKeyPressed, bool isRightKeyPressed) {
    dy += 0.1;
    positionY += dy;

    if (isLeftKeyPressed) {
        positionX -= 1;
    }
    if (isRightKeyPressed) {
        positionX += 1;
    }

    if (positionY <= GROUND_LEVEL) {
        positionY = GROUND_LEVEL;
    } else if (positionY >= 200) { // bottom of the screen, height
        dy -= 8;
    }

    // replace 320 by width
    if (positionX >= 320) {
        positionX = 0;
    } else if (positionX < 0) {
        positionX = 320;
    }
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

void Doodle::update() {

}