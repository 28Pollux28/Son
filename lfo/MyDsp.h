#ifndef faust_teensy_h_
#define faust_teensy_h_

#include "Arduino.h"
#include "AudioStream.h"
#include "Audio.h"

#include "Phasor.h"
#include "Echo.h"
#include "Sine.h"

class MyDsp : public AudioStream
{
  public:
    MyDsp();
    ~MyDsp();
    
    virtual void update(void);
    void setFreq(float freq);
    void setSineFreq(float freq);
    
  private:
    Phasor sawtooth;
    Echo echo;
    Sine sine;
    float f;
    
};

#endif
