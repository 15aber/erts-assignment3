#include "PowerOnSelfTest.h"

Mode* PowerOnSelfTest::instance_ = 0;

Mode* PowerOnSelfTest::getInstance()
{
	if(instance_ == 0)
	{
		instance_ = new PowerOnSelfTest();
	}

	return instance_;
}

//void PowerOnSelfTest::selfTestFailed(EmbeddedSystemX*, int ErrorNo)
//{}


void PowerOnSelfTest::selfTestOK(EmbeddedSystemX* esx){
	chMode(esx, Initializing::getInstance());
}