#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CurrentSamplesRangeDetection.h"

static char resultBuffer[100]; 
CurrentSamplesInfo CurrentSampleInfo[100] ;


void ClearResultBuffer()
{
    for(int i = 0;i<100;i++)
    {
        resultBuffer[i] = 0;
    }
}

int compareForAscending(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

void SortArrayInAscendingOrder(int *CurrentSample,int CurrentSamplesize)
{
    qsort(&CurrentSample[0],CurrentSamplesize,sizeof(int), compareForAscending);
}

char* PrintCSVFormattedOutput(CurrentSamplesInfo *Report ,int CountForRangeSeparation)
{
    
    printf("Range, Readings\n");
    char temp[20];
    ClearResultBuffer();
    for(int count = 0;count<=CountForRangeSeparation;count++)
    {
        sprintf(temp,"%d-%d, %d\n",Report[count].Start,Report[count].End,Report[count].Count);
        strcat(resultBuffer,temp);
        printf("%d-%d, %d\n",Report[count].Start,Report[count].End,Report[count].Count);
    }
    return resultBuffer;
}
int FindStartIndex(int *CurrentSample , int size, int start )
{
    int start_index;
    
    for( int index = 0; index<size ;index++)
    {
        if( CurrentSample[index]>= start)
        {
            start_index = index;
            break;
        }
    }
    return start_index;
}

int FindEndIndex(int *CurrentSample,int size,int start_index,int end)
{
    int end_index;
    
    for(int index = start_index;index<size;index++)
    {
        if(CurrentSample[index]>end)
        {
            end_index = index -1;
            break;
        }
        if(index == size - 1)
        {
           end_index = index ; 
        }
    }
    return end_index;
}

int Check_ArrayContinous(int start_index,int end_index,int* CurrentSample,int*count )
{
    int FailedArrayIndex = 0;
    int flag = 1;
    *count = 0 ;
    for ( int index = start_index ;index<end_index;index++)
    {
        
        int elementDifference = (CurrentSample[index+1] - CurrentSample[index]) ;
        (*count)++;
        if (elementDifference >=2 )
        {
            flag = 0;
            FailedArrayIndex = index + 1;
            break;
        }
    }
    return flag,FailedArrayIndex ;
}

void UpdateCurrentSampleInfo( int CountForRangeSeparation,int start_index,int end_index,int count,int*CurrentSample)
{
    CurrentSampleInfo[CountForRangeSeparation].Start = CurrentSample[start_index];
    CurrentSampleInfo[CountForRangeSeparation].End = CurrentSample[end_index];
    CurrentSampleInfo[CountForRangeSeparation].Count = count;
    
}

char* ChargingCurrentRangeDetection(int start,int end,int *CurrentSample,int CurrentSamplesize ) 
{
    char*Output ;
    int start_index ,end_index,ContinousFlag,count = 0;
    int FailedArrayIndex=1;
    int CountForRangeSeparation = 0;
    int loopiterationexitCount;

    SortArrayInAscendingOrder(&CurrentSample[0],CurrentSamplesize);
    start_index = FindStartIndex(CurrentSample,CurrentSamplesize,start);
    end_index = FindEndIndex(CurrentSample,CurrentSamplesize,start_index,end);
	ContinousFlag, FailedArrayIndex = Check_ArrayContinous(start_index,end_index,CurrentSample,&count) ;
	if(FailedArrayIndex ==0 )
	{
		count = end_index - start_index + 1;
		UpdateCurrentSampleInfo(CountForRangeSeparation,start_index, end_index, count,CurrentSample);
	}
	else 
	{
        start_index = 0;
	    UpdateCurrentSampleInfo(CountForRangeSeparation,start_index, FailedArrayIndex -1, FailedArrayIndex,CurrentSample);
	    loopiterationexitCount = CurrentSamplesize - FailedArrayIndex;

	    while((FailedArrayIndex != 0) && loopiterationexitCount!=0 )
	    {
	        start_index = FailedArrayIndex;
	        ContinousFlag, FailedArrayIndex = Check_ArrayContinous(start_index,end_index,CurrentSample,&count) ;
	        CountForRangeSeparation++;
	        UpdateCurrentSampleInfo(CountForRangeSeparation,start_index, end_index, count,CurrentSample);
	        loopiterationexitCount--;
	    }
	    
	    
	}
	

    Output = PrintCSVFormattedOutput (&CurrentSampleInfo[0],CountForRangeSeparation);
    return Output ;
}
