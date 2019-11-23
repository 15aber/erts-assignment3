#include "Ready.h"
#include <iostream>
#include "RealTimeLoop.h"
#include "Configuration.h"

void Ready::start(EmbeddedSystemX* esx)
{
	std::cout << "Ready: Start" << std::endl;
	//chMode(esx, RealTimeLoop::getInstance());
}

void Ready::configure(EmbeddedSystemX* esx)
{
	std::cout << "Ready: Configure" << std::endl;
	//chMode(esx, Configuration::getInstance());
}
