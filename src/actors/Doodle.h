#ifndef INC_2022_WIN64_DOODLE_H
#define INC_2022_WIN64_DOODLE_H

#include "src/actors/Actor.h"
#include "src/actors/Projectile.h"
#include "Framework.h"

#include <vector>

class Doodle : public Actor {
public:
    Doodle(const std::filesystem::path& spriteLocation, int posX, int posY, double velocityY);

    void jump(int screenHeight, int screenWidth, bool isRightKeyPressed, bool isLeftKeyPressed);
    void fall(bool isLeftKeyPressed, bool isRightKeyPressed);
    void displacementByX(bool isLeftKeyPressed, bool isRightKeyPressed);

    void shoot();
    bool hasUsedProjectile();
    void updateProjectilePosition();

    void die();
private:
    double velocityY;
    Projectile* projectile = nullptr;
};


#endif //INC_2022_WIN64_DOODLE_H
