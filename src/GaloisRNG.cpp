#include "../include/GaloisRNG.hpp"

GaloisRNG::GaloisRNG(int initialSeed) {
    taps = {32, 30, 26, 25};        // tap positions for maximal sequence 32-bit LFSR
    seed = initialSeed;             // the initial loaded value for the register
    lfsrRegister = initialSeed;     // lfsrRegister will contain the current state
    tapsToInt();                    // convert the vector of tap locations into a bitmask
}

unsigned int GaloisRNG::rand() {
    shift();
    return lfsrRegister;
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

void GaloisRNG::shift() {
    bool lowBit = lfsrRegister & 0x01;
    lfsrRegister >>= 1;
    if(lowBit) {
        lfsrRegister ^= tapBinary;
    }
}