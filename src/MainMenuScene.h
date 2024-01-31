#ifndef INC_2022_WIN64_MAINMENUSCENE_H
#define INC_2022_WIN64_MAINMENUSCENE_H

#include "Scene.h"
#include "UIElement.h"

class MainMenuScene : public Scene {
public:
    MainMenuScene();

    void init() override;
    void update() override;
    void render() override;
    void handleInput() override;
    void cleanup() override;

private:
    UIElement* startGameButton;
    UIElement* exitGameButton;
};

#endif //INC_2022_WIN64_MAINMENUSCENE_H
