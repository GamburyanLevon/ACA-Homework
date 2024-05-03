#include "tvRemote.h"
#include <iostream>

void TVRemote::powerOn()
{
    std::cout << "Turning on the TV" << std::endl;
}

void TVRemote::powerOff()  
{
    std::cout << "Turning off the TV" << std::endl;
}

void TVRemote::volumeUp()
{
    std::cout << "Increasing TV volume" << std::endl;
}

void TVRemote::volumeDown()  
{
    std::cout << "Decreasing TV volume" << std::endl;
}

void TVRemote::channelUp()
{
    std::cout << "Switching to the next TV channel" << std::endl;
}

void TVRemote::channelDown()
{
      std::cout << "Switching to the previous TV channel" << std::endl;
}