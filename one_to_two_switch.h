/*
    Test

    Nolan Jome
*/

#ifndef one_to_two_switch_h_
#define one_to_two_switch_h_

#include "Arduino.h"
#include "AudioStream.h"

class OneToTwoSwitch : public AudioStream
{
public:
    AudioEffectPassthrough() : AudioStream(1, inputQueueArray) {};
    virtual void update(void);
    void outputSelect(int chan);
private:
    audio_block_t* inputQueueArray[1];
    int channel = 0;
};

#endif
