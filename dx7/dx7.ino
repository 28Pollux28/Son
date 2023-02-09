#include <Audio.h>
#include "MyDsp.h"

MyDsp myDsp;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(myDsp,0,out,0);
AudioConnection patchCord1(myDsp,0,out,1);

void setup() {
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.5);
  myDsp.setMFreq(440);
  myDsp.setCFreq(1000);
  myDsp.setMFreq3(120,4);
  myDsp.setMFreq3(240,5);
  myDsp.setMFreq3(360,6);
  myDsp.setCFreq3(2000);
}

void loop() {
  myDsp.setCFreq3(analogRead(A0));
  myDsp.setCFreq(analogRead(A2));
  delay(100);
}
