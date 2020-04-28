#ifndef GALOISRNG_H
#define GALOISRNG_H

#include <vector>
#include <cstdint>

/*
 * Implements a 32-bit Galois LFSR to generate pseudo-random numbers
 */
class GaloisRNG {

public:
    
    GaloisRNG(std::uint32_t seed);      // the seed is the value the LFSR will contain initially

    std::uint32_t rand();               // return the next random number from the LFSR
    
    // return a random number between lower and upper inclusive
    unsigned int rand(unsigned int lower, unsigned int upper);

    // getters for testing  
    std::vector<int>& getTaps();
    std::uint32_t getSeed();
    std::uint32_t getTapBinary();

private:

    void shift();                   // actually performs the shift/xor of the LFSR
    void tapsToInt();               // turns the taps vector into a bitmask
    std::vector<int> taps;          // vector containing the position of each XOR tap
    std::uint32_t seed;             // contains the initial value the LFSR was loaded with
    std::uint32_t tapBinary;        // a bitmask representing the tap positions from the taps vector
    std::uint32_t lfsrRegister;     // the current value contained in the LFSR              

};

#endif