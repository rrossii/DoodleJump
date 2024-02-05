#include "src/actors/Actor.h"


Actor::Actor(const std::filesystem::path &spriteLocation, int posX, int posY)
        : sprite(createSprite(spriteLocation.string().c_str())), position({posX, posY}) {}

void Actor::setPosition(int x, int y) {
    position.x = x;
    position.y = y;
}

int Actor::getX() {
    return position.x;
}

int Actor::getY() {
    return position.y;
}

void Actor::render() {
    drawSprite(sprite, position.x, position.y);
}

int Actor::getHeight() {
    getSpriteSize(sprite, dimension.width, dimension.height);

    return dimension.height;
}

int Actor::getWidth() {
    getSpriteSize(sprite, dimension.width, dimension.height);

    return dimension.width;
}

Sprite *Actor::getSprite() {
    return sprite;
}
