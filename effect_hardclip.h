/*
    Hard clipping effect.
    Limits an audio signal to a parameterized level.

    Nolan Jome
*/

#ifndef effect_hardclip_h_
#define effect_hardclip_h_

#include "Arduino.h"
#include "AudioStream.h"

class AudioEffectHardclip : public AudioStream
{
public:
    AudioEffectHardclip() : AudioStream(1, inputQueueArray) {
        clipLevelInt = 32767;
    };
    virtual void update(void);
    void clipLevel(float n);
private:
    audio_block_t *inputQueueArray[1];
    int16_t clipLevelInt;
};

#endif
