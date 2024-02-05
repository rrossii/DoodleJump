#include "Scene.h"

Scene::Scene(int width, int height) : dimensionScreen({width, height}) {}

int Scene::getWidth() {
    return dimensionScreen.width;
}

int Scene::getHeight() {
    return dimensionScreen.height;
}
