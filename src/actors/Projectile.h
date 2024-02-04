#ifndef INC_2022_WIN64_PROJECTILE_H
#define INC_2022_WIN64_PROJECTILE_H

#include "Actor.h"

class Projectile : public Actor {
public:
    Projectile(const std::filesystem::path& spriteLocation, int posX, int posY);
private:
    const int SPEED = 10; //TODO: maybe redo this variable later
};


#endif //INC_2022_WIN64_PROJECTILE_H
