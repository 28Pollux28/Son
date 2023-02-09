#ifndef FM2_H_INCLUDED
#define FM2_H_INCLUDED

#include "SineTable.h"
#include "Phasor.h"

class Fm2{
public:
  Fm2(int SR);
  
  void setC4Freq(float f);
  void setM4Freq(float f);
  void setM5Freq(float f);
  void setM6Freq(float f);
  void setIndex(float i);
  void setGain(float g);
  float tick();
private:
  SineTable sineTable;
  Phasor cPhasor,mPhasor4,mPhasor5,mPhasor6;
  float cFreq,modIndex,gain;
  int samplingRate;
  float divF;
};

#endif  // FM2_H_INCLUDED
