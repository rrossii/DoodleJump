#ifndef INC_2022_WIN64_MAINMENUSCENE_H
#define INC_2022_WIN64_MAINMENUSCENE_H

#include "Scene.h"
#include "src/ui/UIElement.h"

class MainMenuScene : public Scene {
public:
    MainMenuScene(int width, int height);

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
