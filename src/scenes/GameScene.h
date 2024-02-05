#ifndef INC_2022_WIN64_GAMESCENE_H
#define INC_2022_WIN64_GAMESCENE_H

#include "Scene.h"
#include "GameOverScene.h"

#include "src/actors/Doodle.h"
#include "src/actors/Platform.h"
#include "src/actors/Enemy.h"

#include "src/utils/SpriteLocation.h"
#include "src/utils/Randomizer.h"

#include "src/collisions/Collision.h"

#include "src/ui/UIElement.h"
#include "src/ui/UIManager.h"

#include <chrono>
#include <vector>

class GameScene : public Scene {
public:
    GameScene(int width, int height);

    void init() override;
    void update() override;
    void update(bool firstJump, int deltaTime, bool leftKeyIsPressed, bool rightKeyIsPressed);
    void render() override;
    void handleInput() override;
    void cleanup() override;
    void destroySprites() override;

    bool isDoodleDead();
private:
    Doodle* doodlePlayer{};
    std::vector<Platform*> platforms;

    int distancePassed;

    void spawnPlatforms();
    void spawnEnemy();
    void cameraOffset();
};


#endif //INC_2022_WIN64_GAMESCENE_H
