#ifndef GALOISRNG_H
#define GALOISRNG_H

#include <vector>
class GaloisRNG {

public:
    
    GaloisRNG(int);
    GaloisRNG(std::vector<int> taps, int);

    const std::vector<int>& getTaps();
    int getSeed();

private:

    std::vector<int> taps;
    int seed;

};

#endif