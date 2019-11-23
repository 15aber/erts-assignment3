#include "PowerOnSelfTest.h"
#include <iostream>

Mode* PowerOnSelfTest::instance_ = 0;

Mode* PowerOnSelfTest::getInstance()
{	
	if(instance_ == 0)
	{
		instance_ = new PowerOnSelfTest();
	}
	std::cout << "Entering PowerOnSelfTest state";
	return instance_;
}

void PowerOnSelfTest::selfTestFailed(EmbeddedSystemX* esx, int ErrorNo)
{
	std::cout << "PowerOnSelfTest: SelfTestFailed";
	chMode(esx, Failure::getInstance());
}

void PowerOnSelfTest::selfTestOk(EmbeddedSystemX* esx)
{
	std::cout << "PowerOnSelfTest: SelfTest OK";
	chMode(esx, Initializing::getInstance());
}

void PowerOnSelfTest::systemSelfTest(EmbeddedSystemX* esx)
{
	std::cout << "PowerOnSelfTest: Running System Self Test...";
	//selfTestOk(esx);
	selfTestFailed(esx, 1);
}

PowerOnSelfTest::PowerOnSelfTest()
= default;
