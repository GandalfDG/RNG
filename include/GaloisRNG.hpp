#ifndef GALOISRNG_H
#define GALOISRNG_H

#include <vector>
class GaloisRNG {

public:
    
    GaloisRNG(int);

    const std::vector<int>& getTaps();
    int getSeed();
    unsigned int getTapBinary();

private:

    std::vector<int> taps;
    int seed;
    unsigned int tapBinary;

    void tapsToInt();

};

#endif