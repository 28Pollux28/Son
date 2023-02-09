#include "MyDsp.h"

#define AUDIO_OUTPUTS 2

#define MULT_16 32767

MyDsp::MyDsp() : 
AudioStream(AUDIO_OUTPUTS, new audio_block_t*[AUDIO_OUTPUTS]),
sine(AUDIO_SAMPLE_RATE_EXACT),
echo(AUDIO_SAMPLE_RATE_EXACT,10000),
echo2(AUDIO_SAMPLE_RATE_EXACT,10000)
{
  echo.setDel(10000);
  echo.setFeedback(0.5);
  echo2.setDel(10000);
  echo2.setFeedback(0.4);
}


MyDsp::~MyDsp(){}

// set sine wave frequency
void MyDsp::setFreq(float freq){
  sine.setFrequency(freq);
}

void MyDsp::setPlay(bool bPlay){
  play = bPlay;
}

void MyDsp::update(void) {
  audio_block_t* outBlock[AUDIO_OUTPUTS];
  
    for (int channel = 0; channel < AUDIO_OUTPUTS; channel++) {
      outBlock[channel] = allocate();
      if (outBlock[channel]) {
        
        for (int i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {
          float currentSample = 0;
          if(play) {
          float samples[2];
          sine.tick(samples);
          if(channel==0){
            currentSample = echo.tick(max(-1,min(1,samples[0]+0.5*samples[1])));
          }else{
            currentSample = echo2.tick(max(-1,min(1,samples[0]+0.5*samples[1])));
          }
          //currentSample = currentSample/abs(currentSample);
          //currentSample = max(-1,min(1,currentSample));
          
          }
          int16_t val = currentSample*MULT_16;
          outBlock[channel]->data[i] = val;
        }
        transmit(outBlock[channel], channel);
        release(outBlock[channel]);
      
    }
  }
}
