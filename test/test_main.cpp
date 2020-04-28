#include "catch.hpp"
#include "../include/GaloisRNG.hpp"
#include <cstdint>

TEST_CASE("32-bit LFSR RNG is instantiated", "[LFSR]") {
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