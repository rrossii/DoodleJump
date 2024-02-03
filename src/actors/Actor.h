#ifndef INC_2022_WIN64_ACTOR_H
#define INC_2022_WIN64_ACTOR_H

#include "Framework.h"
#include "src/utils/SpriteLocation.h"
#include <filesystem>

class Actor {
public:
    Actor(const std::filesystem::path& spriteLocation, double posX, double posY);

    void setPosition(double x, double y);
    double getX();
    double getY();
    int getHeight();
    int getWidth();

    void render();
protected:
    Sprite* sprite;
    double positionX, positionY;
    int width, height;
};

#endif //INC_2022_WIN64_ACTOR_H
