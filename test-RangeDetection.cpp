#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentSamplesRangeDetection.h"

int samples[]={3,3,5,4,10,11,12};
int size = sizeof(samples)/sizeof(samples[0]) ;
TestLog Info[20];


TEST_CASE("Current Samples RangeDetection Testcase1") {
	int LogCount;
	ChargingCurrentRangeDetection(3,5,&samples[0],size,Info,&LogCount);
    REQUIRE( Info[0].Count == 4);
}
TEST_CASE("Current Samples RangeDetection Testcase2") {
	int LogCount;
	ChargingCurrentRangeDetection(10,12,&samples[0],size,Info,&LogCount);
    REQUIRE( Info[0].Count == 3);
}
TEST_CASE("Current Samples RangeDetection Testcase3") {
	int LogCount;
	ChargingCurrentRangeDetection(4,5,&samples[0],size,Info,&LogCount);
    REQUIRE( Info[0].Count == 2);
}
TEST_CASE("Current Samples RangeDetection Testcase4") {
	int LogCount;
	ChargingCurrentRangeDetection(3,12,&samples[0],size,Info,&LogCount);
        REQUIRE(Info[0].Count ==4 );
	REQUIRE(Info[1].Count ==3 );
}
TEST_CASE("Current Samples RangeDetection Testcase5 -Negative TestCase") {
	int LogCount;
	ChargingCurrentRangeDetection(13,15,&samples[0],size,Info,&LogCount);
    REQUIRE( Info[0].Count == 0);
}
TEST_CASE("Current Samples RangeDetection Testcase6") {
	int LogCount;
	ChargingCurrentRangeDetection(3,3,&samples[0],size,Info,&LogCount);
    REQUIRE( Info[0].Count == 2);
}

