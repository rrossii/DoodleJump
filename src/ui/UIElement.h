#ifndef INC_2022_WIN64_UIELEMENT_H
#define INC_2022_WIN64_UIELEMENT_H

#include <filesystem>
#include "src/utils/Position.h"

class UIElement {
public:
    UIElement(const std::filesystem::path& spriteLocation, Position position);

    std::filesystem::path getSpriteLocation();
    int getX();
    int getY();
private:
    const std::filesystem::path uiSpriteLocation;
    Position position;
};

#endif //INC_2022_WIN64_UIELEMENT_H
