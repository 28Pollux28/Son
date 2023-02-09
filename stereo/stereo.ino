#include <Audio.h>
#include "MyDsp.h"
#include <math.h>

MyDsp myDsp;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(myDsp,0,out,0);
AudioConnection patchCord1(myDsp,1,out,1);

void setup() {
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.5);
  Serial.begin(9600);
  myDsp.setPlay(true);
}

int calcFreqFromMidi(int midiNumber){
  int freq = round(pow(2,float(midiNumber-69-12)/12)*440);
  Serial.println(freq);
  return freq;
}

void loop() {
  myDsp.setFreq(440);
  delay(800);
  myDsp.setFreq(600);
  delay(800);
}
