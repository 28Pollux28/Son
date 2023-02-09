#include <cmath>

#include "Sine2.h"

#define SINE_TABLE_SIZE 16384

Sine2::Sine2(int SR) : 
sineTable(SINE_TABLE_SIZE),
phasor(SR),
gain(1.0),
samplingRate(SR){}

void Sine2::setFrequency(float f){
  phasor.setFrequency(f);
}
    
void Sine2::setGain(float g){
  gain = g;
}
    
void Sine2::tick(float *samples){
  
  int index = phasor.tick()*SINE_TABLE_SIZE;
  samples[0] = sineTable.tick(index)*gain;
  samples[1] = sineTable.tick(int(index*1.5))*gain;
  return ;
}
