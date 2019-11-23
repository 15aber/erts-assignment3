#include "Ready.h"
#include <iostream>
#include "RealTimeLoop.h"
#include "Configuration.h"

Mode* Ready::instance_ = 0;

Mode* Ready::getInstance()
{
	if (instance_ == 0)
	{
		instance_ = new Ready();
	}
	std::cout << "Entering Ready state" << std::endl;
	return instance_;
}


void Ready::start(EmbeddedSystemX* esx)
{
	std::cout << "Ready: Start" << std::endl;
	chMode(esx, RealTimeLoop::getInstance());
}

void Ready::configure(EmbeddedSystemX* esx)
{
	std::cout << "Ready: Configure" << std::endl;
	chMode(esx, Configuration::getInstance());
}
