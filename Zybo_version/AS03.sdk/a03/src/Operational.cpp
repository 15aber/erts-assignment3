#include "Operational.h"
#include <iostream>
#include "PowerOnSelfTest.h"

void Operational::restart(EmbeddedSystemX* esx)
{
	std::cout << "Operational: restart" << std::endl;
	chMode(esx, PowerOnSelfTest::getInstance());
}
