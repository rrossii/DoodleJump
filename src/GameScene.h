#ifndef INC_2022_WIN64_GAMESCENE_H
#define INC_2022_WIN64_GAMESCENE_H

#include "Scene.h"
#include "Doodle.h"
#include "Platform.h"
#include <chrono>
#include <vector>

class GameScene : public Scene {
public:
    GameScene();

    void init() override;
    void update() override;
    void update(bool leftKeyIsPressed, bool rightKeyIsPressed);
    void render() override;
    void handleInput() override;
    void cleanup() override;
private:
    Doodle* doodlePlayer;
    std::vector<Platform*> platforms;
    std::chrono::steady_clock::time_point prevFrameTime;
};


#endif //INC_2022_WIN64_GAMESCENE_H
