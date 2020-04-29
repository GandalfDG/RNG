#include <iostream>
#include "../include/GaloisRNG.hpp"
#include "../include/FisherYates.hpp"

#define SEED 867530908
#define VECLEN 15

using std::cout;

void printVector(std::vector<unsigned int>);

int main() {
    GaloisRNG rng(SEED);
    FisherYates shuffler(rng);

    cout << "32-bit Galois LFSR with taps at ";
    for(auto tap : rng.getTaps()) {
        cout << tap << " ";
    }
    cout  << "and seeded with " << SEED << "." << std::endl;

    cout << std::endl << "here is a sequence of random numbers following the seed value: " << std::endl;
    for(auto i = 0u; i < 10; i++) {
        cout << rng.rand() << " ";
    }

    cout << std::endl << std::endl << "I have verified that the LFSR produces all non-zero values representable by a 32-bit integer" << std::endl;
    cout << "However, this takes a while to run, so it has been omitted from this demonstration." << std::endl;
    cout << "There is a test for it in the test suite." << std::endl << std::endl;

    std::vector<unsigned int> vec;
    for(auto i = 0u; i < VECLEN; i++) {
        vec.push_back(i);
    }
    cout << "Now the Galois LFSR random number generator will be used to shuffle the following vector:" << std::endl;
    printVector(vec);

    shuffler.shuffle(vec);
    cout << std::endl << "After shuffling:" << std::endl;
    printVector(vec);

    shuffler.shuffle(vec);
    cout << std::endl << "And again:" << std::endl;
    printVector(vec);
} 

void printVector(std::vector<unsigned int> vec) {
    cout << "{ ";
    for(auto i = 0u; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "}" << std::endl;
}