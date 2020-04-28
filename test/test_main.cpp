#include <cstdint>

#include "catch.hpp"

#include "../include/GaloisRNG.hpp"
#include "../include/FisherYates.hpp"

TEST_CASE("32-bit Galois LFSR", "[LFSR]") {
    unsigned int seed = 123;
    GaloisRNG rng(seed);

  SECTION("default taps are the taps for maximal sequence") {

    REQUIRE(rng.getTaps().size() == 4);
    REQUIRE(rng.getTaps()[0] == 32);
    REQUIRE(rng.getTaps()[3] == 25);

    REQUIRE(rng.getTapBinary() == 0xa3000000);
    
    }

    SECTION("seed the RNG") {

        REQUIRE( rng.getSeed() == seed);

    }

    SECTION("get first value out") {

        REQUIRE(rng.rand() == 0xa300003d);
    }

    // this takes a while, but I just wanted to be sure
    // SECTION("ensure maximal sequence", "[.slow]") {
    //     long count = 1;
    //     while(rng.rand() != seed) {
    //         count++;
    //     }
    //     REQUIRE(count == UINT32_MAX);
    // }

    SECTION("get random value in range") {

        REQUIRE(rng.rand(1u, 6u) == 6);

    }

}

TEST_CASE("Shuffle algorithm implementation") {
    GaloisRNG rng(8675309);
    FisherYates shuffler(rng);

    SECTION("small vector shuffle") {
        std::vector<std::uint32_t> deck = {1, 2, 3, 4, 5};
        
    }

}