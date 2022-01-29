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
    audio_block_t* block;

    block = receiveReadOnly(inputPort);
    if (!block) return;

    transmit(block, outputPort);
    release(block);

    return;
}

void outputSelect(int in, int out) {
    if (chan >= 0 && chan <= 2) {
        channel = chan;
    }
}