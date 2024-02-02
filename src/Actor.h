#ifndef INC_2022_WIN64_ACTOR_H
#define INC_2022_WIN64_ACTOR_H

#include "Framework.h"
#include "SpriteLocation.h"
#include <filesystem>

class Actor {
public:
    Actor(const std::filesystem::path& spriteLocation, double posX, double posY);

    void setPosition(double x, double y);
    double getX();
    double getY();

    void render();
protected:
    Sprite* sprite;
    double positionX, positionY;
};

#endif //INC_2022_WIN64_ACTOR_H
