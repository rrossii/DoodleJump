#ifndef INC_2022_WIN64_DOODLE_H
#define INC_2022_WIN64_DOODLE_H

#include "src/actors/Actor.h"
#include "src/actors/Projectile.h"
#include "Framework.h"

class Doodle : public Actor {
public:
    Doodle(const std::filesystem::path& spriteLocation, double posX, double posY, double velocityY);

    void jump(int screenHeight, int screenWidth, double deltaTime, bool isRightKeyPressed, bool isLeftKeyPressed);
    void fall(int screenWidth, bool isLeftKeyPressed, bool isRightKeyPressed);
    void displacementByX(int screenWidth, bool isLeftKeyPressed, bool isRightKeyPressed);

    void shoot(Projectile* projectile);
private:
    double velocityY;
    bool isJumping;
};


#endif //INC_2022_WIN64_DOODLE_H
