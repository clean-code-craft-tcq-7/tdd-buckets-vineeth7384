#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentSamplesRangeDetection.h"

int samples[]={3,3,5,4,10,11,12};
int size = sizeof(samples)/sizeof(samples[0]) ;

TEST_CASE("Current Samples RangeDetection Testcase1") {
  REQUIRE( ChargingCurrentRangeDetection(3,5,&samples[0],size) == 4);
}
TEST_CASE("Current Samples RangeDetection Testcase2") {
  REQUIRE( ChargingCurrentRangeDetection(10,12,&samples[0],size) == 3);
}
TEST_CASE("Current Samples RangeDetection Testcase3") {
  REQUIRE( ChargingCurrentRangeDetection(4,5,&samples[0],size) == 2);
}

