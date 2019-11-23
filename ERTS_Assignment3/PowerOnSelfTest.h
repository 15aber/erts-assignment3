#pragma once
#include "Mode.h"
#include "Initializing.h"
class PowerOnSelfTest :
	public Mode
{
public:
	static Mode* getInstance();

	void selfTestFailed(EmbeddedSystemX*, int ErrorNo) override;
	void selfTestOk(EmbeddedSystemX*) override;

	void systemSelfTest(); //own
	
protected:
	PowerOnSelfTest();

private:
	static Mode* instance_;
};

