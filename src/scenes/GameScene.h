#ifndef INC_2022_WIN64_GAMESCENE_H
#define INC_2022_WIN64_GAMESCENE_H

#include "Scene.h"
#include "src/actors/Doodle.h"
#include "src/actors/Platform.h"
#include "src/actors/Enemy.h"
#include <chrono>
#include <vector>

class GameScene : public Scene {
public:
    GameScene(int width, int height);

    void init() override;
    void update() override;
    void update(bool leftKeyIsPressed, bool rightKeyIsPressed);
    void render() override;
    void handleInput() override;
    void cleanup() override;

    void spawnPlatforms();
    void spawnEnemies();
private:
    Doodle* doodlePlayer{};
    std::vector<Platform*> platforms;
    std::vector<Enemy*> enemies;
    std::chrono::steady_clock::time_point prevFrameTime;
};


#endif //INC_2022_WIN64_GAMESCENE_H
