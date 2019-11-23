#include "Initializing.h"
#include <iostream>

Mode* Initializing::instance_ = 0;

Mode* Initializing::getInstance()
{
	if (instance_ == 0)
	{
		instance_ = new Initializing();
	}
	std::cout << "In Initializing state";
	return instance_; 
}

void Initializing::initialized(EmbeddedSystemX* esx)
{
 std::cout << "Initializing: initialize";
 //chMode(esx, Operational::getInstance());
}

void Initializing::startInitializing()
{
	std::cout << "Initializing: Start Initializing";
}

Initializing::Initializing()
{
}
