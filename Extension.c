#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Extension.h"

int convert_to_amps_12BITADC( int a2d_reading)
{
    return (int)round ((a2d_reading/(double)MAX_12BIT_A2D_READING) * MAX_AMPS_12BIT_A2D );
}

int convert_to_amps_10BITADC( int a2d_reading)
{
   if(a2d_reading == MID_10BIT_A2D_READING)
    {
        return 0;
    }
    int amps = (int)round (MIN_AMPS_10BIT_A2D + ((a2d_reading - MIN_10BIT_A2D_READING)/(double)(MAX_10BIT_A2D_READING-MIN_10BIT_A2D_READING))*(MAX_AMPS_10BIT_A2D -MIN_AMPS_10BIT_A2D));
    return amps;
}

int validate12BITReading(int a2d_reading)
{
    if (a2d_reading<MIN_12BIT_A2D_READING || a2d_reading>MAX_12BIT_A2D_READING )
    {
        return -1;
    }
    return 0;
}
int validate10BITReading(int a2d_reading)
{
    if (a2d_reading<MIN_10BIT_A2D_READING || a2d_reading>MAX_10BIT_A2D_READING )
    {
        return -1;
    }
    return 0;
}
int absolute_value ( int number)
{
    return abs(number);
}