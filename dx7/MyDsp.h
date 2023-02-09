#ifndef faust_teensy_h_
#define faust_teensy_h_

#include "Arduino.h"
#include "AudioStream.h"
#include "Audio.h"

#include "fm2.h"
#include "Fm.h"

class MyDsp : public AudioStream
{
  public:
    MyDsp();
    ~MyDsp();
    
    virtual void update(void);
    void setCFreq(float freq);
    void setMFreq(float freq);
    void setIndex(float i);
    void setGain(float gain);
    void setMFreq3(float freq, int id);
    void setCFreq3(float freq);
    
  private:
    Fm fm1;
    Fm2 fm3;
};

#endif
