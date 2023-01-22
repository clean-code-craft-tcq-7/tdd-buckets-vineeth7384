#include <stdio.h>
#include<stdlib.h>

int ChargingCurrentRangeDetection(int start,int end,int *CurrentSample,int CurrentSamplesize  ) 
{
    int count = 0;
    for(int i =0;i<CurrentSamplesize;i++)
    {
        if(CurrentSample[i]>= start && CurrentSample[i]<=end)
        {
            count++;
        }
    }
    
    printf("%d-%d %d\n",start,end,count);
    
    return count; 
    
}
