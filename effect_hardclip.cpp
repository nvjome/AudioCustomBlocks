/*
	Nolan Jome
*/

#include "Arduino.h"
#include "effect_hardclip.h"

//#define INT16_MAX 32767

/*
	update

	Update function called by the Audio library every update cycle.
*/
void AudioEffectHardclip::update(void) {
	audio_block_t *block = receiveWritable();
	if (!block) return;

	int16_t *point = block->data;
	int16_t *end = block->data + AUDIO_BLOCK_SAMPLES;

	for (; point < end; point++) {
		int sample = *point;

		if (sample > clipLevelInt) {
			sample = clipLevelInt;
			*point = sample;
		}
		if (sample < -clipLevelInt) {
			sample = -clipLevelInt;
			*point = sample;
		}
	}

	transmit(block);
	release(block);

	return;
}

/*
	clipLevel

	Public function to set the level to clip the audio data.
	Takes floating value from 0.0 to 1.0.
	Setting to 1.0 would have no effect on the samples.
*/
void AudioEffectHardclip::clipLevel(float n) {
	if (n > 1.0f) {
		n = 1.0f;
	} else if (n < 0.0f) {
		n = 0.0f;
	}

	clipLevelInt = n * 32767;
}