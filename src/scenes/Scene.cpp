#include "Scene.h"

Scene::Scene(int width, int height) : screenWidth(width), screenHeight(height) {}

int Scene::getWidth() {
    return screenWidth;
}

int Scene::getHeight() {
    return screenHeight;
}
