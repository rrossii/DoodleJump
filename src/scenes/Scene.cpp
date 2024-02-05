#include "Scene.h"

Scene::Scene(int width, int height) : dimensionScreen({width, height}) {}

int Scene::getSceneWidth() {
    return dimensionScreen.width;
}

int Scene::getSceneHeight() {
    return dimensionScreen.height;
}
