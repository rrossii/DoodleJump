#include "src/utils/SpriteLocation.h"

const std::filesystem::path SpriteLocation::getFolder() {
    return R"(C:\Users\annro\Desktop\doodle jump task\2022_win64\data\)";
}

const std::filesystem::path SpriteLocation::getDoodleSpriteLocation() {
    return getFolder() / R"(blue-lik-left@2x.png)";
}

const std::filesystem::path SpriteLocation::getDoodleShootingSpriteLocation() {
    return getFolder() / R"(blue-lik-puca@2x.png)";
}

const std::filesystem::path SpriteLocation::getProjectileSpriteLocation() {
    return getFolder() / R"(projectile@2x.png)";
}

const std::filesystem::path SpriteLocation::getButterflyEnemySpriteLocation() {
    return getFolder() / R"(enemy-butterfly@2x.png)";
}

const std::filesystem::path SpriteLocation::getPlatformSpriteLocation() {
    return getFolder() / R"(platform@2x.png)";
}

const std::filesystem::path SpriteLocation::getPlayAgainButtonSpriteLocation() {
    return getFolder() / R"(play-again-on@2x.png)";
}

const std::filesystem::path SpriteLocation::getScoresButtonSpriteLocation() {
    return getFolder() / R"(scores-on@2x.png)";
}

const std::filesystem::path SpriteLocation::getTallEnemySpriteLocation() {
    return getFolder() / R"(enemy-tall@2x.png)";
}

//const std::filesystem::path SpriteLocation::getJumperSpriteLocation() {
//    return std::filesystem::path();
//}
//
//const std::filesystem::path SpriteLocation::getSpringSpriteLocation() {
//    return std::filesystem::path();
//}
//
//const std::filesystem::path SpriteLocation::getJetpackSpriteLocation() {
//    return std::filesystem::path();
//}
//
//const std::filesystem::path SpriteLocation::getPlayButtonSpriteLocation() {
//    return std::filesystem::path();
//}
//
//const std::filesystem::path SpriteLocation::getExitButtonSpriteLocation() {
//    return std::filesystem::path();
//}
