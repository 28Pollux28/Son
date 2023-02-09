#include <Audio.h>
#include "MyDsp.h"
#include <math.h>

MyDsp myDsp;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(myDsp,0,out,0);
AudioConnection patchCord1(myDsp,0,out,1);

void setup() {
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.5);
  Serial.begin(9600);
  pinMode(0,INPUT);
}

int calcFreqFromMidi(int midiNumber){
  int freq = round(pow(2,float(midiNumber-69-12)/12)*440);
  Serial.println(freq);
  return freq;
}

void loop() {
  if(digitalRead(0)){
    myDsp.setGain(1.0);
  }else{
    myDsp.setGain(0.0);
  }
  
  myDsp.setFreq(analogRead(A0)+100);
//  delay(400);
  myDsp.setFreq(calcFreqFromMidi(79));
//  delay(400);
//  myDsp.setFreq(calcFreqFromMidi(79));
//  delay(400);
//  myDsp.setFreq(calcFreqFromMidi(75));
//  delay(300);
//  myDsp.setFreq(calcFreqFromMidi(82));
//  delay(100);
//  myDsp.setFreq(calcFreqFromMidi(79));
//  delay(400);
//  myDsp.setFreq(calcFreqFromMidi(75));
//  delay(300);
//  myDsp.setFreq(calcFreqFromMidi(82));
//  delay(100);
//  myDsp.setFreq(calcFreqFromMidi(79));
//  delay(400);
//  delay(1000);
//  delay(1000);
}
