#include "src/ui/UIElement.h"


UIElement::UIElement(const std::filesystem::path& spriteLocation, Position position)
         : uiSprite(createSprite(spriteLocation.string().c_str())), position(position) {
}

int UIElement::getX() {
    return position.x;
}

int UIElement::getY() {
    return position.y;
}

int UIElement::getHeight() {
    getSpriteSize(uiSprite, dimension.width, dimension.height);

    return dimension.height;
}

int UIElement::getWidth() {
    getSpriteSize(uiSprite, dimension.width, dimension.height);

    return dimension.width;
}

Sprite *UIElement::getSprite() {
    return uiSprite;
}

void UIElement::render() {
    drawSprite(uiSprite, position.x, position.y);
}

