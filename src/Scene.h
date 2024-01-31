
#ifndef INC_2022_WIN64_SCENE_H
#define INC_2022_WIN64_SCENE_H

class Scene {
public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual void handleInput() = 0;
    virtual void cleanup() = 0;
};


#endif //INC_2022_WIN64_SCENE_H
