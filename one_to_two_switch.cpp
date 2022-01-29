/*
    Nolan Jome
*/

#include "Arduino.h"
#include "one_to_two_switch.h"

/*
    update()

    Update function called by the Audio library every update cycle.
*/
void OneToTwoSwitch::update(void) {
    audio_block_t *block;

    block = receiveReadOnly();
    if (!block) return;

    transmit(block, channel);
    release(block);

    return;
}

void outputSelect(int chan) {
    if (chan >= 0 && chan <= 2) {
        channel = chan;
    }
}