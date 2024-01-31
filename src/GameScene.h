#ifndef INC_2022_WIN64_GAMESCENE_H
#define INC_2022_WIN64_GAMESCENE_H

#include "Scene.h"
#include "Doodle.h"

class GameScene : public Scene {
public:
    GameScene();

    void init() override;
    void update() override;
    void render() override;
    void handleInput() override;
    void cleanup() override;
private:
    Doodle* doodlePlayer;
};


#endif //INC_2022_WIN64_GAMESCENE_H
