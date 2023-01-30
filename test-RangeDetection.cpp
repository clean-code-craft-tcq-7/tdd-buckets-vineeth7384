#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentSamplesRangeDetection.h"
#include<string.h>


int samples[]={3,3,5,4,10,11,12};
int size = sizeof(samples)/sizeof(samples[0]) ;


TEST_CASE("Given 4,5 as input when ChargingCurrentRangeDetection called then 4-5,2 is expected ") {
	int result;
	char*str = ChargingCurrentRangeDetection(4,5,&samples[0],size);
	const char *expected = "4-5, 2\n" ;
	result = strcmp(expected,str);
	REQUIRE(result == 0 );
	
}

TEST_CASE("Given 3,4 as input when ChargingCurrentRangeDetection called then 3-4,3 is expected ") {
	int result;
	char*str = ChargingCurrentRangeDetection(3,4,&samples[0],size);
	const char *expected = "3-4, 3\n" ;
	result = strcmp(expected,str);
	REQUIRE(result == 0 );
	
}

TEST_CASE("Given 3,3 as input when ChargingCurrentRangeDetection called then 3-3,2 is expected ") {
	int result;
	char*str = ChargingCurrentRangeDetection(3,4,&samples[0],size);
	const char *expected = "3-3, 2\n" ;
	result = strcmp(expected,str);
	REQUIRE(result == 0 );
	
}


TEST_CASE("Given 3,10 as input when ChargingCurrentRangeDetection called then 3-5,4 10-10,1 is expected ") {
	int result;
	char*str = ChargingCurrentRangeDetection(3,10,&samples[0],size);
	const char *expected = "3-5, 4\n10-10, 1\n" ; 
	result = strcmp(expected,str);
	REQUIRE(result == 0 );
	
}

TEST_CASE("Given 3,12 as input when ChargingCurrentRangeDetection called then 3-5,4 10-12,3 is expected ") {
	int result;
	char*str = ChargingCurrentRangeDetection(3,12,&samples[0],size);
	const char *expected = "3-5, 4\n10-12, 3\n" ;
	result = strcmp(expected,str);
	REQUIRE(result == 0 );
	
}


