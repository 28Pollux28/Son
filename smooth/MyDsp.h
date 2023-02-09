#ifndef faust_teensy_h_
#define faust_teensy_h_

#include "Arduino.h"
#include "AudioStream.h"
#include "Audio.h"

#include "Phasor.h"
#include "Echo.h"

class MyDsp : public AudioStream
{
  public:
    MyDsp();
    ~MyDsp();
    
    virtual void update(void);
    void setFreq(float freq);
    void setOldFreq(float freq);
    
  private:
    Phasor sawtooth;
    Echo echo;
    float s,s1;
    float freq1,oldFreq;
};

#endif
