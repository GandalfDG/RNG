#include "GaloisRNG.hpp"

GaloisRNG::GaloisRNG(int initialSeed) {
    taps = {32, 30, 26, 25};
    seed = initialSeed;
    tapsToInt();
}

const std::vector<int>& GaloisRNG::getTaps() {
    return taps;
}

int GaloisRNG::getSeed() {
    return seed;
}

unsigned int GaloisRNG::getTapBinary() {
    return tapBinary;
}

void GaloisRNG::tapsToInt() {
    unsigned int tapmask = 0;
    for(auto tap : taps) {
        tapmask |= 1 << (tap - 1);
    }
    tapBinary = tapmask;
}