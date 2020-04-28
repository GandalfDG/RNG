#ifndef FISHERYATES_H
#define FISHERYATES_H

#include "GaloisRNG.hpp"
#include <cstdint>

class FisherYates {

public:
    FisherYates(GaloisRNG& rngref);

    void shuffle(std::vector<std::uint32_t>&);

private:
    GaloisRNG rng;


};

#endif