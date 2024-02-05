#ifndef INC_2022_WIN64_UIELEMENT_H
#define INC_2022_WIN64_UIELEMENT_H

#include <filesystem>
#include "src/utils/Position.h"
#include "src/utils/Dimension.h"
#include "Framework/Framework.h"

class UIElement {
public:
    UIElement(const std::filesystem::path& spriteLocation, Position position);

    Sprite* getSprite();
    void render();

    int getX();
    int getY();
    int getWidth();
    int getHeight();
private:
    Sprite* uiSprite;
    Position position;
    Dimension dimension;
};

#endif //INC_2022_WIN64_UIELEMENT_H
