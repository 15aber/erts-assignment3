#include "Failure.h"
#include <iostream>
#include <stdlib.h>

Mode* Failure::instance_ = 0;

Mode* Failure::getInstance()
{	
	if(instance_ == 0)
	{
		instance_ = new Failure();
	}
	std::cout << "Entering Failure state" << std::endl;
	return instance_;
}


void Failure::restart(EmbeddedSystemX* esx)
{
	std::cout << "Failure: restarting" << std::endl;
	chMode(esx, PowerOnSelfTest::getInstance());
}

void Failure::exitStateMachine(EmbeddedSystemX* esx)
{
	std::cout << "Failure: Leaving the program" << std::endl;
	exit(0);
}

void Failure::display(EmbeddedSystemX* esx, int ErrorNo)
{
	std::cout << "Failure: Error No: " << ErrorNo << " encountered."<< std::endl;
	// restart(esx);
	exitStateMachine(esx);
}

Failure::Failure()
{
}

