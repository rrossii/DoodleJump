#include "Randomizer.h"

int Randomizer::getRandomNumber(int startRange, int endRange) {
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::uniform_int_distribution<> distribution(startRange, endRange);

    int randomNumber = distribution(generator);
    return randomNumber;
}
