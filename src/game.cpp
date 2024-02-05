#include <iostream>
#include <sstream>

#include "Framework/Framework.h"
#include "src/scenes/GameScene.h"
#include "src/scenes/GameOverScene.h"

#include "src/utils/Dimension.h"

class MyFramework : public Framework {
private:
    Dimension dimensionScreen;
    bool isFullscreen;

    bool upKeyIsPressed = false;
    bool downKeyIsPressed = false;
    bool rightKeyIsPressed = false;
    bool leftKeyIsPressed = false;

    bool isLeftMouseButtonPressed = false;
    bool isRightMouseButtonPressed = false;
    bool isMiddleMouseButtonPressed = false;

    bool gameOverSceneRendered = false;
    
    std::unique_ptr<GameScene> startGame;
    std::unique_ptr<GameOverScene> gameOver;
    bool doodleFall = false;

    std::chrono::steady_clock::time_point prevFrameTime = std::chrono::steady_clock::time_point::min();
    std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();

public:
    MyFramework(int argc, char** argv) {
        if (argc == 0) {
            dimensionScreen.width = 320;
            dimensionScreen.height = 200;
            isFullscreen = false;
        } else if (argc > 1) {
            if (argv[1] == "-window") {
                std::string sizeArg = argv[2];
                std::stringstream ss(sizeArg);
                char x;
                ss >> dimensionScreen.width >> x >> dimensionScreen.height;
                isFullscreen = false;

                if (ss.fail() || x != 'x') {
                    std::cerr << "Invalid window size format, should be like this: WidthxHeight\n";
                    exit(-1);
                }
            }
        }
        startGame = std::make_unique<GameScene>(dimensionScreen.width, dimensionScreen.height);
        gameOver = std::make_unique<GameOverScene>(dimensionScreen.width, dimensionScreen.height);
    };
    
	virtual void PreInit(int& width, int& height, bool& fullscreen) {
        width = dimensionScreen.width;
        height = dimensionScreen.height;
        fullscreen = isFullscreen;
    }

	virtual bool Init() {
        startGame->init();

		return true;
	}

    virtual void Close() {
        startGame->destroySprites();
        startGame->cleanup();
        gameOver->destroySprites();
        gameOver->cleanup();
    }

	virtual bool Tick() {
        drawTestBackground();

        prevFrameTime = currentTime;
        currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> delta = currentTime - prevFrameTime;
        int deltaTime = delta.count();

        if (upKeyIsPressed && !doodleFall) {
            startGame->update(true, deltaTime, leftKeyIsPressed, rightKeyIsPressed);
            doodleFall = true;
        }

        if (!gameOverSceneRendered) {
            startGame->render();
        }

        if (doodleFall) {
            startGame->update(false, deltaTime, leftKeyIsPressed, rightKeyIsPressed);
            if (startGame->isDoodleDead()) {
                gameOver->init();
                gameOver->render();

                gameOverSceneRendered = true;
            }
        }

        if (downKeyIsPressed) {
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