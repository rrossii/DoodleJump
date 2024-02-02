#ifndef INC_2022_WIN64_DOODLE_H
#define INC_2022_WIN64_DOODLE_H

#include "Actor.h"
#include "Framework.h"

class Doodle : public Actor {
public:
    Doodle(const std::filesystem::path& spriteLocation, double posX, double posY, double velocityY);

    void jump(double deltaTime, bool isRightKeyPressed, bool isLeftKeyPressed);
    void update();
private:
    double velocityY;
    bool isJumping;
};


#endif //INC_2022_WIN64_DOODLE_H
