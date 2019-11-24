#include "RealTimeLoop.h"
#include <iostream>
#include "Ready.h"
#include "Suspended.h"

Mode* RealTimeLoop::instance_ = 0;

Mode* RealTimeLoop::getInstance()
{
	if (instance_ == 0)
	{
		instance_ = new RealTimeLoop();
	}
	std::cout << "Entering RealTimeLoop state" << std::endl;
	return instance_;
}

void RealTimeLoop::stop(EmbeddedSystemX* esx)
{
	std::cout << "RealTimeLoop: Stop" << std::endl;
	chMode(esx, Ready::getInstance());
}

void RealTimeLoop::suspend(EmbeddedSystemX* esx)
{
	std::cout << "RealTimeLoop: Suspend" << std::endl;
	chMode(esx, Suspended::getInstance());
}
