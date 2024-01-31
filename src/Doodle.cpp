#include "Doodle.h"
#include "Framework.h"

Doodle::Doodle() :
            velocityY(0.),
            positionY(0.), positionX(0.),
            isJumping(false),
            doodleSprite(createSprite("C:\\Users\\annro\\Desktop\\doodle jump task\\2022_win64\\data\\blue-lik-left@2x.png")){}

void Doodle::jump() {
    isJumping = true;
    double gravity = 10;
    double ground = 0;
    double deltaTime = getTickCount();

    velocityY -= gravity * deltaTime;
    positionY += velocityY * deltaTime;

    if (positionY <= ground) {
        positionY = ground;
        velocityY = 0.;
        isJumping = false;
    }
}

void Doodle::render() {
    drawSprite(doodleSprite, positionY, positionX);
}
