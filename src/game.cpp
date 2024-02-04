#include "Framework.h"
#include "src/scenes/GameScene.h"
#include <iostream>
#include <sstream>


class MyFramework : public Framework {
private:
    int screenWidth;
    int screenHeight;
    bool isFullscreen;

    bool upKeyIsPressed = false;
    bool downKeyIsPressed = false;
    bool rightKeyIsPressed = false;
    bool leftKeyIsPressed = false;

    bool isLeftMouseButtonPressed = false;
    bool isRightMouseButtonPressed = false;
    bool isMiddleMouseButtonPressed = false;
    
    std::unique_ptr<GameScene> startGame;
    bool doodleFall = false;

public:
    MyFramework(int argc, char** argv) {
        if (argc == 0) {
            screenWidth = 320;
            screenHeight = 200;
            isFullscreen = false;
        } else if (argc > 1) {
            if (argv[1] == "-window") {
                std::string sizeArg = argv[2];
                std::stringstream ss(sizeArg);
                char x;
                ss >> screenWidth >> x >> screenHeight;
                isFullscreen = false;

                if (ss.fail() || x != 'x') {
                    std::cerr << "Invalid window size format, should be like this: WidthxHeight\n";
                    exit(-1);
                }
            }
        }
        startGame = std::make_unique<GameScene>(screenWidth, screenHeight);
    };
    
	virtual void PreInit(int& width, int& height, bool& fullscreen) {
        width = screenWidth;
        height = screenHeight;
        fullscreen = isFullscreen;
    }

	virtual bool Init() {
        startGame->init();

		return true;
	}

	virtual void Close() {

	}

	virtual bool Tick() {
        drawTestBackground();

        if (upKeyIsPressed) {
            doodleFall = true;
        }
        if (doodleFall) {
            startGame->update(leftKeyIsPressed, rightKeyIsPressed);
        }
//        startGame->render();
//        startGame->update(leftKeyIsPressed, rightKeyIsPressed);
        startGame->render();

        if (downKeyIsPressed) {
            startGame->cleanup();
            return true;
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

int main()
{
    char* argv[] = {"game", "-window", "800x800", nullptr};
	return run(new MyFramework(4, argv));
}

//int main(int argc, char* argv[])
//{
//    return run(new MyFramework(argc, argv));
//}