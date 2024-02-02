#include "Actor.h"


Actor::Actor(const std::filesystem::path& spriteLocation, double posX, double posY)
    : sprite(createSprite(spriteLocation.string().c_str())), positionX(posX), positionY(posY) {}

void Actor::setPosition(double x, double y) {
    positionX = x;
    positionY = y;
}

double Actor::getX() {
    return positionX;
}

double Actor::getY() {
    return positionY;
}

void Actor::render() {
    drawSprite(sprite, positionX, positionY);
}
