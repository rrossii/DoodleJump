#include "Framework.h"
#include "MainMenuScene.h"
#include "GameScene.h"
#include <iostream>


class MyFramework : public Framework {
private:
    bool upKeyIsPressed = false;
    bool downKeyIsPressed = false;
    bool rightKeyIsPressed = false;
    bool leftKeyIsPressed = false;

public:
	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = 320;
		height = 200;
		fullscreen = false;
	}

	virtual bool Init() {

		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
        drawTestBackground();

        GameScene startGame;
        startGame.init();
        if (upKeyIsPressed) {
            startGame.update();
            startGame.render();
        }

		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {

	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {

	}

	virtual void onKeyPressed(FRKey k) {
        switch (k) {
            case FRKey::UP:
                upKeyIsPressed = true;
                break;
            case FRKey::DOWN:
                downKeyIsPressed = true;
                break;
            case FRKey::RIGHT:
                rightKeyIsPressed = true;
                break;
            case FRKey::LEFT:
                leftKeyIsPressed = true;
                break;
        }
	}

	virtual void onKeyReleased(FRKey k) {
        switch (k) {
            case FRKey::UP:
                upKeyIsPressed = false;
                break;
            case FRKey::DOWN:
                downKeyIsPressed = false;
                break;
            case FRKey::RIGHT:
                rightKeyIsPressed = false;
                break;
            case FRKey::LEFT:
                leftKeyIsPressed = false;
                break;
        }
	}
	
	virtual const char* GetTitle() override
	{
		return "Doodle Jump";
	}
};

int main(int argc, char *argv[])
{
	return run(new MyFramework);
}
