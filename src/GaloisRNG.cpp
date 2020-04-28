#include "GaloisRNG.hpp"

GaloisRNG::GaloisRNG(int seed) {
    taps = {32, 30, 26, 25};
    GaloisRNG(taps, seed);
}

GaloisRNG::GaloisRNG(std::vector<int> taps, int seed) {
    taps = taps;
    seed = seed;
}

const std::vector<int>& GaloisRNG::getTaps() {
    return taps;
}

int GaloisRNG::getSeed() {
    return seed;
}