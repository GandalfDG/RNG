#ifndef GALOISRNG_H
#define GALOISRNG_H

#include <vector>
class GaloisRNG {

public:
    
    GaloisRNG(int);

    unsigned int rand();

    const std::vector<int>& getTaps();
    int getSeed();
    unsigned int getTapBinary();

private:

    void shift();
    std::vector<int> taps;
    int seed;
    unsigned int tapBinary;
    unsigned int lfsrRegister;

    void tapsToInt();

};

#endif