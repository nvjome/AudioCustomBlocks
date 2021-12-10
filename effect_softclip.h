/*
    Soft clipping effect.
    Limits an audio signal to a parameterized level while rounding off the transition.

	Nolan Jome
*/

#ifndef effect_softclip_h_
#define effect_softclip_h_

#include "Arduino.h"
#include "AudioStream.h"

class AudioEffectSoftclip : public AudioStream
{
public:
	AudioEffectSoftclip() : AudioStream(1, inputQueueArray) {};
	virtual void update(void);
private:
	audio_block_t *inputQueueArray[1];
};

#endif
