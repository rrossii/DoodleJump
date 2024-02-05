#ifndef INC_2022_WIN64_ACTOR_H
#define INC_2022_WIN64_ACTOR_H

#include "Framework.h"
#include "src/utils/SpriteLocation.h"
#include "src/utils/Position.h"
#include "src/utils/Dimension.h"
#include <filesystem>

class Actor {
public:
    Actor(const std::filesystem::path& spriteLocation, int posX, int posY);

    void setPosition(int x, int y);

    int getX();
    int getY();
    int getHeight();
    int getWidth();
    Sprite* getSprite();

    void render();
protected:
    Sprite* sprite;
    Position position;
    Dimension dimension;
};

#endif //INC_2022_WIN64_ACTOR_H
