#include "Initializing.h"
#include <iostream>

Mode* Initializing::instance_ = 0;

Mode* Initializing::getInstance()
{
	if (instance_ == 0)
	{
		instance_ = new Initializing();
	}
	std::cout << "Entering Initializing state";
	return instance_; 
}

void Initializing::initialized(EmbeddedSystemX* esx)
{
 std::cout << "Initializing: Initialized";
 //chMode(esx, Operational::getInstance());
}

void Initializing::startInitializing(EmbeddedSystemX* esx)
{
	std::cout << "Initializing: Start Initializing";
	initialized(esx);
}

Initializing::Initializing()
{
}
