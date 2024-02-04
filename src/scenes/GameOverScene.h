#ifndef INC_2022_WIN64_GAMEOVERSCENE_H
#define INC_2022_WIN64_GAMEOVERSCENE_H

#include "Scene.h"
#include "src/ui/UIElement.h"
#include "src/ui/UIManager.h"

#include "src/utils/Position.h"
#include "src/utils/SpriteLocation.h"

class GameOverScene : public Scene {
public:
    GameOverScene(int width, int height);

    void init() override;
    void update() override;
    void render() override;
    void handleInput() override;
    void cleanup() override;
    void destroySprites() override;

private:
    UIElement* playAgainButton;
    UIElement* scores;
};


#endif //INC_2022_WIN64_GAMEOVERSCENE_H
