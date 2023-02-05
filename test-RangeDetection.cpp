#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "CurrentSamplesRangeDetection.h"
#include "Extension.h"
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
	char*str = ChargingCurrentRangeDetection(3,3,&samples[0],size);
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


TEST_CASE("Given 0,10 as input when ChargingCurrentRangeDetection called then 3-5,4 10-10,1 is expected ") {
	int result;
	char*str = ChargingCurrentRangeDetection(0,10,&samples[0],size);
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
TEST_CASE("Given 5,16 as input when ChargingCurrentRangeDetection called then 5-5,1 10-12,3 is expected ") {
	int result;
	char*str = ChargingCurrentRangeDetection(5,16,&samples[0],size);
	const char *expected = "5-5, 1\n10-12, 3\n" ;
	result = strcmp(expected,str);
	REQUIRE(result == 0 );
	
}
TEST_CASE("Given2000 as input when convert_to_amps_12BITADC called then 5 is expected ") {
	int adcresult = -1;
	int validate12BITReadResult = -1 ;
	int a2d_reading = 2000;
	validate12BITReadResult = validate12BITReading(a2d_reading);
	if (validate12BITReadResult == 0)
    {
         adcresult = convert_to_amps_12BITADC(a2d_reading);
    }
	REQUIRE(adcresult == 5 );
}
TEST_CASE("Given5000 as input when convert_to_amps_12BITADC called then error is expected ") {
	int adcresult = -1;
	int validate12BITReadResult = -1 ;
	int a2d_reading = 5000;
	validate12BITReadResult = validate12BITReading(a2d_reading);
	if (validate12BITReadResult == 0)
    {
         adcresult = convert_to_amps_12BITADC(a2d_reading);
    }
	REQUIRE(adcresult == -1 );
}
TEST_CASE("Given1000 as input when convert_to_amps_10BITADC called then 5 is expected ") {
	int adcresult = -1;
	int validate10BITReadResult = -1 ;
	int a2d_reading = 1000;
	validate10BITReadResult = validate10BITReading(a2d_reading);
	if (validate10BITReadResult == 0)
    {
         adcresult = convert_to_amps_10BITADC(a2d_reading);
    }
	REQUIRE(adcresult == 14 );
}
TEST_CASE("Given 2000 as input when convert_to_amps_10BITADC called then error is expected ") {
	int adcresult = -1;
	int validate10BITReadResult = -1 ;
	int a2d_reading = 2000;
	validate10BITReadResult = validate10BITReading(a2d_reading);
	if (validate10BITReadResult == 0)
    {
         adcresult = convert_to_amps_10BITADC(a2d_reading);
    }
	REQUIRE(adcresult == -1 );
}
TEST_CASE("Given -15 as input when absolute_value called then 15 is expected ") {
	int result =0 ;
	result = absolute_value(-15);
	REQUIRE(result == 15 );
}
