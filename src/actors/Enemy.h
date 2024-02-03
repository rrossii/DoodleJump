#ifndef INC_2022_WIN64_ENEMY_H
#define INC_2022_WIN64_ENEMY_H

#include "Actor.h"

class Enemy : public Actor {
public:
    Enemy(const std::filesystem::path& spriteLocation, double posX, double posY, bool isDead);
private:
    bool dead = false;
};


#endif //INC_2022_WIN64_ENEMY_H
