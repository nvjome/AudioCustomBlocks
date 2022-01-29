/*
    Test

    Nolan Jome
*/

#ifndef two_to_two_switch_h_
#define two_to_two_switch_h_

#include "Arduino.h"
#include "AudioStream.h"

class OneToTwoSwitch : public AudioStream
{
public:
    AudioEffectPassthrough(int inCnt, int outCnt) : AudioStream(inPortCnt, inputQueueArray) {
        inPortCnt = inCnt;
        outPortCnt = outCnt;
    };
    virtual void update(void);
    void outputSelect(int in, int out);
private:
    new audio_block_t* inputQueueArray[inPortCount];
    int inputPort = 0;
    int outputPort = 0;
    int inPortCnt;
    int outPortCnt;
};

#endif
