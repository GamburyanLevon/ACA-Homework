#include <iostream>
#include "tvRemote.h"

int main() {
    TVRemote tvRemote;

    tvRemote.powerOn();
    tvRemote.volumeUp();
    tvRemote.channelUp();
    tvRemote.volumeDown();
    tvRemote.powerOff();

    return 0;
}