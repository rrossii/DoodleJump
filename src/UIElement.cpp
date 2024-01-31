#include "UIElement.h"
#include "Framework.h"


UIElement::UIElement(const std::filesystem::path spriteLocation) : spriteLocation(spriteLocation) {
}

void UIElement::render() {
    auto sprite = createSprite(spriteLocation.string().c_str());
    drawSprite(sprite, 100, 100);
}
