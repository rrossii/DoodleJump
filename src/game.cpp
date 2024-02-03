#include "Framework.h"
#include "src/scenes/GameScene.h"
#include <iostream>
#include <sstream>


class MyFramework : public Framework {
private:
    int screenWidth = 320, screenHeight = 200;

    bool upKeyIsPressed = false;
    bool downKeyIsPressed = false;
    bool rightKeyIsPressed = false;
    bool leftKeyIsPressed = false;

    bool isLeftMouseButtonPressed = false;
    bool isRightMouseButtonPressed = false;
    bool isMiddleMouseButtonPressed = false;

    GameScene startGame;
    bool doodleFall = false;

    int argc;
    char** argv;

public:
    MyFramework(int argc, char** argv) : argc(argc), argv(argv) {

    };
    
	virtual void PreInit(int& width, int& height, bool& fullscreen) {
        if (argc > 1) {
            if (argv[1] == "-window") {
                std::string sizeArg = argv[2];
                std::stringstream ss(sizeArg);
                char x;
                ss >> width >> x >> height;
                fullscreen = false;

                if (ss.fail() || x != 'x') {
                    std::cerr << "Invalid window size format, should be like this: WidthxHeight\n";
                }
            }
        } else {
            width = 320;
            height = 200;
            fullscreen = false;
        }
        screenWidth = width;
        screenHeight = height;
    }

	virtual bool Init() {
        startGame.init();
        int w, h;
        getScreenSize(w, h);
        std::cout << w << " " << h;

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
            startGame.update(leftKeyIsPressed, rightKeyIsPressed);
        }
        startGame.render();

        if (downKeyIsPressed) {
            startGame.cleanup();
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
    char* argv[] = {"game", "-window", "600x600", nullptr};
	return run(new MyFramework(4, argv));
}

//int main(int argc, char* argv[])
//{
//    return run(new MyFramework(argc, argv));
//}