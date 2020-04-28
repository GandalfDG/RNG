#include <iostream>
#include "../include/GaloisRNG.hpp"

int main() {
    GaloisRNG rng(4141996);

    for(int i = 0; i < 100; i++) {
        std::cout << rng.rand(1, 10) << std::endl;
    }

    return 0;
}