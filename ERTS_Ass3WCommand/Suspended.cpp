	#include "Suspended.h"
#include "Ready.h"
#include <ostream>
#include <iostream>
#include "RealTimeLoop.h"

Mode* Suspended::instance_ = 0;

Mode* Suspended::getInstance()
{
	if (instance_ == 0)
	{
		instance_ = new Suspended();
	}
	std::cout << "Entering Suspended state" << std::endl;
	return instance_;
}

void Suspended::stop(EmbeddedSystemX* esx)
{
	std::cout << "Suspended: Stop" << std::endl;
	chMode(esx, Ready::getInstance());
}

void Suspended::resume(EmbeddedSystemX* esx)
{
	std::cout << "Suspended: Resume" << std::endl;
	chMode(esx, RealTimeLoop::getInstance());
}
