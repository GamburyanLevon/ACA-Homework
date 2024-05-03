#include "remote.h"

class TVRemote : public Remote {
public:
    void powerOn() override;

    void powerOff() override;

    void volumeUp() override;

    void volumeDown() override;

    void channelUp() override;

    void channelDown() override;
};