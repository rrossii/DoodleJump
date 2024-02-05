#include "src/ui/UIElement.h"
#include "Framework/Framework.h"


UIElement::UIElement(const std::filesystem::path& spriteLocation, Position position)
         : uiSpriteLocation(spriteLocation), position(position) {
}

std::filesystem::path UIElement::getSpriteLocation() {
    return uiSpriteLocation;
}

int UIElement::getX() {
    return position.x;
}

int UIElement::getY() {
    return position.y;
}

