#ifndef INC_2022_WIN64_DOODLE_H
#define INC_2022_WIN64_DOODLE_H

#include "Actor.h"
#include "Framework.h"

class Doodle : public Actor {
public:
    Doodle();

    void jump();
    void render();
private:
    Sprite* doodleSprite;
    double velocityY;
    double positionY, positionX;
    bool isJumping;
};


#endif //INC_2022_WIN64_DOODLE_H
