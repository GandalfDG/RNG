#ifndef GALOISRNG_H
#define GALOISRNG_H

#include <vector>
#include <cstdint>

class GaloisRNG {

public:
    
    GaloisRNG(std::uint32_t seed);

    std::uint32_t rand();
    unsigned int rand(unsigned int, unsigned int);

    std::vector<int>& getTaps();
    std::uint32_t getSeed();
    std::uint32_t getTapBinary();

private:

    void shift();
    std::vector<int> taps;
    std::uint32_t seed;
    std::uint32_t tapBinary;
    std::uint32_t lfsrRegister;

    void tapsToInt();

};

#endif