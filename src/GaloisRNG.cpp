#include "../include/GaloisRNG.hpp"

GaloisRNG::GaloisRNG(std::uint32_t initialSeed) {
    taps = {32, 30, 26, 25};        // tap positions for maximal sequence 32-bit LFSR
    seed = initialSeed;             // the initial loaded value for the register
    lfsrRegister = initialSeed;     // lfsrRegister will contain the current state
    tapsToInt();                    // convert the vector of tap locations into a bitmask
}

std::uint32_t GaloisRNG::rand() {
    shift();
    return lfsrRegister;
}

unsigned int GaloisRNG::rand(unsigned int lowerBound, unsigned int upperBound) {
    // stackoverflow tells me this isn't uniform, but I think that's fine
    return lowerBound + rand() % ((upperBound + 1) - lowerBound);
}

std::vector<int>& GaloisRNG::getTaps() {
    return taps;
}

unsigned int GaloisRNG::getSeed() {
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
    // give my regards to wikipedia https://en.wikipedia.org/wiki/Linear-feedback_shift_register#Galois_LFSRs
    bool lowBit = lfsrRegister & 0x01;
    lfsrRegister >>= 1;
    if(lowBit) {
        lfsrRegister ^= tapBinary;
    }
}