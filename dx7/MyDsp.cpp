#include "MyDsp.h"

#define AUDIO_OUTPUTS 1

#define MULT_16 32767

MyDsp::MyDsp() : 
AudioStream(AUDIO_OUTPUTS, new audio_block_t*[AUDIO_OUTPUTS]),
fm1(AUDIO_SAMPLE_RATE_EXACT),
fm3(AUDIO_SAMPLE_RATE_EXACT)
{
}

MyDsp::~MyDsp(){}

void MyDsp::setCFreq(float freq){
  fm1.setCFreq(freq);
}

void MyDsp::setMFreq(float freq){
  fm1.setMFreq(freq);
}

void MyDsp::setMFreq3(float freq, int id){
  if(id == 4){
    fm3.setM4Freq(freq);
  }else if(id==5){
    fm3.setM5Freq(freq);
  }else if(id==6){
    fm3.setM6Freq(freq);
  }
}

void MyDsp::setCFreq3(float freq){
  fm3.setC4Freq(freq);
}

void MyDsp::setIndex(float freq){
  fm1.setIndex(freq);
}

// set sine wave gain
void MyDsp::setGain(float gain){
  fm1.setGain(gain);
}

void MyDsp::update(void) {
  audio_block_t* outBlock[AUDIO_OUTPUTS];
  for (int channel = 0; channel < AUDIO_OUTPUTS; channel++) {
    outBlock[channel] = allocate();
    if (outBlock[channel]) {
      for (int i = 0; i < AUDIO_BLOCK_SAMPLES; i++) {
        float currentSample = fm1.tick()*0.45 + fm3.tick()*0.45;
        currentSample = max(-1,min(1,currentSample));
        int16_t val = currentSample*MULT_16;
        outBlock[channel]->data[i] = val;
      }
      transmit(outBlock[channel], channel);
      release(outBlock[channel]);
    }
  }
}
