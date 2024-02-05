#ifndef INC_2022_WIN64_DOODLE_H
#define INC_2022_WIN64_DOODLE_H

#include "src/actors/Actor.h"
#include "src/actors/Projectile.h"
#include "Framework/Framework.h"

#include <vector>

class Doodle : public Actor {
public:
    Doodle(const std::filesystem::path& spriteLocation, int posX, int posY, double velocityY);

    void jump(int screenHeight, int screenWidth, double deltaTime, bool isRightKeyPressed, bool isLeftKeyPressed);
    void fall(double deltaTime, int screenWidth, bool isLeftKeyPressed, bool isRightKeyPressed);
    void displacementByX(int screenWidth, bool isLeftKeyPressed, bool isRightKeyPressed);

    void shoot();
    bool hasUsedProjectile();
    void updateProjectilePosition();

private:
    double velocityY;
    bool isJumping;
    Projectile* projectile;
};


#endif //INC_2022_WIN64_DOODLE_H
