/*
    Nolan Jome
*/

#include "Arduino.h"
#include "ten_to_one_mux.h"

/*
    update()

    Update function called by the Audio library every update cycle.
*/
void AudioTenToOneMux::update(void) {
    audio_block_t *block;

    block = receiveReadOnly(channel);
    if (!block) return;

    transmit(block);
    release(block);

    return;
}

void AudioTenToOneMux::inputSelect(int chan) {
    if (chan >= 0 && chan < inPortCnt) {
        channel = chan;
    }
}