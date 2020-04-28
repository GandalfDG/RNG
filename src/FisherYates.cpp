#include <cstdint>
#include "../include/FisherYates.hpp"

FisherYates::FisherYates(GaloisRNG& rngref): rng(rngref) {}

void FisherYates::shuffle(std::vector<std::uint32_t> &vec) {
    // adapted from pseudocode found here: https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle#The_modern_algorithm
    std::uint32_t randIdx = 0;
    std::uint32_t temp = 0;

    for(unsigned int i = 0; i < (vec.size() - 2); i++) {
        randIdx = rng.rand(i, vec.size() - 1);
        temp = vec[i];
        vec[i] = vec[randIdx];
        vec[randIdx] = temp;
    }
}