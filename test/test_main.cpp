#include "catch.hpp"
#include "GaloisRNG.hpp"

TEST_CASE("32-bit LFSR RNG is instantiated", "[LFSR]") {
    GaloisRNG rng(123);

    SECTION("default taps are the taps for maximal sequence") {
        
        REQUIRE( rng.getTaps().size() == 4 );
        REQUIRE( rng.getTaps()[0] == 32 );
        REQUIRE( rng.getTaps()[3] == 25 );    
    
    }

    SECTION("seed the RNG") {

        REQUIRE( rng.getSeed() == 123);
        
    }

}