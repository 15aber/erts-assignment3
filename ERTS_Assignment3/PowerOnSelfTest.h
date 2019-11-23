#pragma once
#include "Mode.h"
#include "Initializing.h"
class PowerOnSelfTest :
	public Mode
{
public:
	static Mode* getInstance();

	virtual void selfTestFailed(EmbeddedSystemX*, int ErrorNo);
	virtual void selfTestOK(EmbeddedSystemX*);

	void systemSelfTest(); //own

protected:
	PowerOnSelfTest();
private:
	static Mode* instance_;
};

