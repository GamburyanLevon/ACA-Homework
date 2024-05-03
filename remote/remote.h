#pragma once

class Remote {
public:
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
    virtual void volumeUp() = 0;
    virtual void volumeDown() = 0;
    virtual void channelUp() = 0;
    virtual void channelDown() = 0;
};
