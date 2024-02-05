#ifndef INC_2022_WIN64_PLATFORM_H
#define INC_2022_WIN64_PLATFORM_H

#include "src/actors/Actor.h"
#include "src/actors/Enemy.h"


class Platform : public Actor {
public:
    Platform(int x, int y);
    void addEnemyOnPlatform(Enemy* enemy);
    void deleteEnemyFromPlatform();
    bool hasEnemyOnPlatform();

    Enemy* getEnemy();
private:
    bool hasEnemy = false;
    Enemy* enemy = nullptr;
};


#endif //INC_2022_WIN64_PLATFORM_H
