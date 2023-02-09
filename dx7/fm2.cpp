#include <cmath>

#include "fm2.h"

#define SINE_TABLE_SIZE 16384

Fm2::Fm2(int SR) : 
sineTable(SINE_TABLE_SIZE),
cPhasor(SR),
mPhasor4(SR),
mPhasor5(SR),
mPhasor6(SR),
cFreq(440.0),
modIndex(100.0),
gain(1.0),
divF(1/3.0),
samplingRate(SR){}


void Fm2::setC4Freq(float f){
  cFreq = f;
}

void Fm2::setM4Freq(float f){
  mPhasor4.setFrequency(f);
}

void Fm2::setM5Freq(float f){
  mPhasor5.setFrequency(f);
}

void Fm2::setM6Freq(float f){
  mPhasor6.setFrequency(f);
}

void Fm2::setIndex(float i){
  modIndex = i;
}
    
void Fm2::setGain(float g){
  gain = g;
}
    
float Fm2::tick(){
  int mIndex4 = mPhasor4.tick()*SINE_TABLE_SIZE;
  int mIndex5 = mPhasor5.tick()*SINE_TABLE_SIZE;
  int mIndex6 = mPhasor6.tick()*SINE_TABLE_SIZE;
  float modulator = sineTable.tick(mIndex4)+sineTable.tick(mIndex5)+sineTable.tick(mIndex6);
  modulator = modulator * divF;
  cPhasor.setFrequency(cFreq + modulator*modIndex);
  int cIndex = cPhasor.tick()*SINE_TABLE_SIZE;
  return sineTable.tick(cIndex)*gain;
}
