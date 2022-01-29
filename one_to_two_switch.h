/*
    One input to two output switch.
    The input can be passed to any individual output, allowing
    advanced audio routing without needing to (dis)connect
    AudioConnection objects.

    Nolan Jome
*/

#ifndef one_to_two_switch_h_
#define one_to_two_switch_h_

#include "Arduino.h"
#include "AudioStream.h"

class AudioOneToTwoSwitch : public AudioStream
{
public:
    AudioOneToTwoSwitch() : AudioStream(1, inputQueueArray) {};
    virtual void update(void);
    void outputSelect(int chan);
private:
    audio_block_t* inputQueueArray[1];
    int channel = 0;
};

#endif
