#ifndef FISHERYATES_H
#define FISHERYATES_H

#include "GaloisRNG.hpp"
#include <cstdint>

class FisherYates {

public:
    // construct the shuffler with a GaloisRNG object for randomness
    FisherYates(GaloisRNG& rngref);

    // shuffle the provided vector in place
    void shuffle(std::vector<std::uint32_t>&);

private:
    // the rng object used for shuffling
    GaloisRNG rng;
};

#endif