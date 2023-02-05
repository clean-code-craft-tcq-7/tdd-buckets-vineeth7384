#define MAX_12BIT_A2D_READING 4094
#define MIN_12BIT_A2D_READING 0
#define MAX_AMPS_12BIT_A2D  10
#define MIN_10BIT_A2D_READING 0
#define MAX_10BIT_A2D_READING 1023
#define MID_10BIT_A2D_READING 511
#define MIN_AMPS_10BIT_A2D -15
#define MAX_AMPS_10BIT_A2D 15

int convert_to_amps_12BITADC( int a2d_reading);
int convert_to_amps_10BITADC( int a2d_reading);
int validate12BITReading(int a2d_reading);
int validate10BITReading(int a2d_reading);
int absolute_value ( int number);