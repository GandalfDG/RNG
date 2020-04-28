#include <iostream>
#include "../include/GaloisRNG.hpp"
#include "../include/FisherYates.hpp"

using std::cout;

int main() {
    unsigned int seed = 8675309;
    GaloisRNG rng(seed);
    FisherYates shuffler(rng);

    cout << "32-bit Galois LFSR with taps at " << rng.getTaps().data() << " and seeded with " << seed << std::endl;
}