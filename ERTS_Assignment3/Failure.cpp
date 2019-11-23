#include "Failure.h"
#include <iostream>

Mode* Failure::instance_ = 0;

Mode* Failure::getInstance()
{	
	if(instance_ == 0)
	{
		instance_ = new Failure();
	}
	std::cout << "Entering Failure state";
	return instance_;
}


void Failure::restart(EmbeddedSystemX* esx)
{
	std::cout << "Failure: restarting";
	chMode(esx, PowerOnSelfTest::getInstance());
}

void Failure::display(EmbeddedSystemX* esx, int ErrorNo)
{
	std::cout << "Failure: Error No: " << ErrorNo << " encountered."<< std::endl;
	restart(esx);
}

Failure::Failure()
{
}

