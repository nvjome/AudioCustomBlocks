/*
	Nolan Jome
*/

#include "Arduino.h"
#include "effect_softclip.h"

/*
	update

	Update function called by the Audio library every update cycle.
*/
void AudioEffectSoftclip::update(void) {
	audio_block_t *block;

	block = receiveReadOnly();
	if (!block) return;

	transmit(block);
	release(block);

	return;
}