typedef struct 
{
  int Start;
  int End;
  int Count;
}TestLog;
void ChargingCurrentRangeDetection(int start,int end,int *CurrentSample,int CurrentSamplesize, TestLog *CurrentSampleLog ,int*CurrentSampleLogCount ); 