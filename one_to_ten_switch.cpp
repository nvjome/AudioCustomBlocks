/*
    Nolan Jome
*/

#include "Arduino.h"
#include "one_to_ten_switch.h"

/*
    update()

    Update function called by the Audio library every update cycle.
*/
void AudioOneToTenSwitch::update(void) {
    audio_block_t *block;

    block = receiveReadOnly();
    if (!block) return;

    transmit(block, channel);
    release(block);

    return;
}

void AudioOneToTenSwitch::outputSelect(int chan) {
    if (chan >= 0 && chan < outPortCnt) {
        channel = chan;
    }
}