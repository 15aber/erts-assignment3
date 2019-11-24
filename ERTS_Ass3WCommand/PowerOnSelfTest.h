#pragma once
#include "Mode.h"
#include "Initializing.h"
#include "Failure.h"
class PowerOnSelfTest :
	public Mode
{
public:
	static Mode* getInstance();

	void selfTestFailed(EmbeddedSystemX*, int ErrorNo) override;
	void selfTestOk(EmbeddedSystemX*) override;

	void systemSelfTest(EmbeddedSystemX*); //own
	
protected:
	PowerOnSelfTest();

private:
	static Mode* instance_;
};

