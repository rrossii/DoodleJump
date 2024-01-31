#ifndef INC_2022_WIN64_UIELEMENT_H
#define INC_2022_WIN64_UIELEMENT_H

#include <filesystem>

class UIElement {
public:
    UIElement(const std::filesystem::path spriteLocation);

    void render();
private:
    const std::filesystem::path spriteLocation;
};

#endif //INC_2022_WIN64_UIELEMENT_H
