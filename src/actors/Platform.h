#ifndef INC_2022_WIN64_PLATFORM_H
#define INC_2022_WIN64_PLATFORM_H

#include "src/actors/Actor.h"
#include "src/actors/Enemy.h"


class Platform : public Actor {
public:
    Platform(int x, int y);
    Enemy* getEnemy();
    void setEnemy(Enemy* enemy);
    void removeEnemy();
    bool hasEnemy();

private:
    Enemy* enemy = nullptr;
};


#endif //INC_2022_WIN64_PLATFORM_H
