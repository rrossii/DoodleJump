#ifndef INC_2022_WIN64_COLLISION_H
#define INC_2022_WIN64_COLLISION_H

#include "src/actors/Actor.h"
#include "src/actors/Doodle.h"
#include "src/actors/Platform.h"

class Collision {
public:
    static bool isColliding(Doodle* doodle, Platform* platform);
    static bool doodleDieFromEnemy(Doodle* doodle, Enemy* enemy);
    static bool doodleKillEnemy(Doodle* doodle, Enemy* enemy);
//    static bool isColliding(Enemy* enemy, Projectile* projectile);
};


#endif //INC_2022_WIN64_COLLISION_H
