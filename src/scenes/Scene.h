#ifndef INC_2022_WIN64_SCENE_H
#define INC_2022_WIN64_SCENE_H

class Scene {
public:
    Scene(int width, int height);

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void handleInput() = 0;
    virtual void cleanup() = 0;
    virtual void destroySprites() = 0;

protected:
    int getWidth();
    int getHeight();

private:
    int screenWidth, screenHeight;
};

#endif //INC_2022_WIN64_SCENE_H
