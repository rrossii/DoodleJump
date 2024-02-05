#ifndef INC_2022_WIN64_SPRITELOCATION_H
#define INC_2022_WIN64_SPRITELOCATION_H

#include <filesystem>
#include <string>

class SpriteLocation {
public:
    static const std::filesystem::path getFolder();

    static const std::filesystem::path getDoodleSpriteLocation();
    static const std::filesystem::path getDoodleShootingSpriteLocation();

    static const std::filesystem::path getPlatformSpriteLocation();

    static const std::filesystem::path getProjectileSpriteLocation();

    static const std::filesystem::path getButterflyEnemySpriteLocation();
    static const std::filesystem::path getTallEnemySpriteLocation();

    static const std::filesystem::path getJumperSpriteLocation();
    static const std::filesystem::path getSpringSpriteLocation();
    static const std::filesystem::path getJetpackSpriteLocation();

    static const std::filesystem::path getPlayAgainButtonSpriteLocation();
    static const std::filesystem::path getPlayButtonSpriteLocation();
    static const std::filesystem::path getScoresButtonSpriteLocation();
    static const std::filesystem::path getExitButtonSpriteLocation();

};


#endif //INC_2022_WIN64_SPRITELOCATION_H
