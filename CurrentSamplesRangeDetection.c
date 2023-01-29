#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CurrentSamplesRangeDetection.h"

static char resultBuffer[100]; 
int StartRange ;
int EndRange;
int CountForRangeCalculation = 0;
int count ;

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

char* PrintCSVFormattedOutput(CurrentSamplesInfo *Report ,int CountForRangeCalculation)
{
    
    printf("Range, Readings\n");
    char temp[20];
    ClearResultBuffer();
    for(int count = 0;count<=CountForRangeCalculation;count++)
    {
        sprintf(temp,"%d-%d, %d\n",Report[count].Start,Report[count].End,Report[count].Count);
        strcat(resultBuffer,temp);
        printf("%d-%d, %d\n",Report[count].Start,Report[count].End,Report[count].Count);
    }
    return resultBuffer;
}

void FindRangeofNonDuplicateElements(int *CurrentSample,int i)
{
    if(CurrentSample[i] +1 == CurrentSample[i+1])
    {

        count++ ;
        EndRange = CurrentSample[i+1];
    }
    else
    {
        CountForRangeCalculation +=1 ;
        count= 1;
        StartRange = CurrentSample[i+1] ;
        EndRange = CurrentSample[i+1] ;
    }
    
}


void RangeValidation(int start,int end,int *CurrentSample,int i)
{
    if(CurrentSample[i]>= start && CurrentSample[i]< end)
    {
        if (CurrentSample[i]==CurrentSample[i+1])
        {
            count = count+1;
        }
            
        else
        {
            FindRangeofNonDuplicateElements(&CurrentSample[0],i);
        }
    }
    
}

char* ChargingCurrentRangeDetection(int start,int end,int *CurrentSample,int CurrentSamplesize ) 
{
    StartRange = start ;
    EndRange = start;
    CountForRangeCalculation = 0;
    count = 1;
    char*Output ;
    CurrentSamplesInfo CurrentSampleInfo[CurrentSamplesize] ;
    SortArrayInAscendingOrder(&CurrentSample[0],CurrentSamplesize);
    
    for(int i =0;i<CurrentSamplesize;i++)
    {
        RangeValidation(start,end,&CurrentSample[0],i);
        CurrentSampleInfo[CountForRangeCalculation].Start = StartRange;
        CurrentSampleInfo[CountForRangeCalculation].End = EndRange;
        CurrentSampleInfo[CountForRangeCalculation].Count = count;
    }
    Output = PrintCSVFormattedOutput (&CurrentSampleInfo[0] ,CountForRangeCalculation);
    return Output ;

}
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"CurrentSamplesRangeDetection.h"

static char resultBuffer[100]; 
int StartRange ;
int EndRange;
int CountForRangeCalculation = 0;
int count ;

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

char* PrintCSVFormattedOutput(CurrentSamplesInfo *Report ,int CountForRangeCalculation)
{
    
    printf("Range, Readings\n");
    char temp[20];
    ClearResultBuffer();
    for(int count = 0;count<=CountForRangeCalculation;count++)
    {
        sprintf(temp,"%d-%d, %d\n",Report[count].Start,Report[count].End,Report[count].Count);
        strcat(resultBuffer,temp);
        printf("%d-%d, %d\n",Report[count].Start,Report[count].End,Report[count].Count);
    }
    return resultBuffer;
}

void FindRangeofNonDuplicateElements(int *CurrentSample,int i)
{
    if(CurrentSample[i] +1 == CurrentSample[i+1])
    {

        count++ ;
        EndRange = CurrentSample[i+1];
    }
    else
    {
        CountForRangeCalculation +=1 ;
        count= 1;
        StartRange = CurrentSample[i+1] ;
        EndRange = CurrentSample[i+1] ;
    }
    
}


void RangeValidation(int start,int end,int *CurrentSample,int i)
{
    if(CurrentSample[i]>= start && CurrentSample[i]< end)
    {
        if (CurrentSample[i]==CurrentSample[i+1])
        {
            count = count+1;
        }
            
        else
        {
            FindRangeofNonDuplicateElements(&CurrentSample[0],i);
        }
    }
    
}

char* ChargingCurrentRangeDetection(int start,int end,int *CurrentSample,int CurrentSamplesize ) 
{
    StartRange = start ;
    EndRange = start;
    CountForRangeCalculation = 0;
    count = 1;
    char*Output ;
    CurrentSamplesInfo CurrentSampleInfo[CurrentSamplesize] ;
    SortArrayInAscendingOrder(&CurrentSample[0],CurrentSamplesize);
    
    for(int i =0;i<CurrentSamplesize;i++)
    {
        RangeValidation(start,end,&CurrentSample[0],i);
        CurrentSampleInfo[CountForRangeCalculation].Start = StartRange;
        CurrentSampleInfo[CountForRangeCalculation].End = EndRange;
        CurrentSampleInfo[CountForRangeCalculation].Count = count;
    }
    Output = PrintCSVFormattedOutput (&CurrentSampleInfo[0] ,CountForRangeCalculation);
    return Output ;

}
