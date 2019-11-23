#include "PowerOnSelfTest.h"
#include <iostream>

Mode* PowerOnSelfTest::instance_ = 0;

Mode* PowerOnSelfTest::getInstance()
{
	if(instance_ == 0)
	{
		instance_ = new PowerOnSelfTest();
	}

	return instance_;
}

void PowerOnSelfTest::selfTestFailed(EmbeddedSystemX* esx, int ErrorNo)
{
	std::cout << "SelfTestFailed";
}

void PowerOnSelfTest::selfTestOk(EmbeddedSystemX* esx)
{
	std::cout << "SelfTest OK";
	chMode(esx, Initializing::getInstance());
}

void PowerOnSelfTest::systemSelfTest()
{
	std::cout << "Running System Self Test...";
}

PowerOnSelfTest::PowerOnSelfTest()
= default;
