#include <stdio.h>
#include<stdlib.h>
#include"CurrentSamplesRangeDetection.h"

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


void ChargingCurrentRangeDetection(int start,int end,int *CurrentSample,int CurrentSamplesize, TestLog *CurrentSampleLog ,int*CurrentSampleLogCount ) 
{
    qsort(&CurrentSample[0],CurrentSamplesize,sizeof(int), cmpfunc);
    
    int count = 1;
    int StartRange = start ;
    int EndRange = start;
    *CurrentSampleLogCount = 0;
    
    for(int i =0;i<CurrentSamplesize;i++)
    {
        if(CurrentSample[i]>= start && CurrentSample[i]<=end)
        {
            
            if (CurrentSample[i]==CurrentSample[i+1])
            {
                count = count+1;
            }
            else
            {
                if (CurrentSample[i] +1 == CurrentSample[i+1])
                {
                    count++ ;
                    EndRange = CurrentSample[i+1];
                    
                }
                else
                {
                    printf("%d-%d %d\n",StartRange,EndRange,count);
                    CurrentSampleLog[*CurrentSampleLogCount].Start = StartRange;
                    CurrentSampleLog[*CurrentSampleLogCount].End = EndRange;
                    CurrentSampleLog[*CurrentSampleLogCount].Count = count;
                    *CurrentSampleLogCount +=1 ;
                    count= 1;
                    StartRange = CurrentSample[i+1] ;
                }
            }
        }
    }

}
