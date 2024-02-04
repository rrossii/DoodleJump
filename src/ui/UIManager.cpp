#include "UIManager.h"

void UIManager::render(UIElement* element) {
    auto uiSprite = createSprite(element->getSpriteLocation().string().c_str());
    drawSprite(uiSprite, element->getX(), element->getY());
}