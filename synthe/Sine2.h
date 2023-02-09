#ifndef SINE_H_INCLUDED
#define SINE_H_INCLUDED

#include "SineTable.h"
#include "Phasor.h"

class Sine2{
public:
  Sine2(int SR);
  
  void setFrequency(float f);
  void setGain(float g);
  void tick(float* samples);
private:
  SineTable sineTable;
  Phasor phasor;
  float gain;
  int samplingRate;
};

#endif  // SINE_H_INCLUDED
