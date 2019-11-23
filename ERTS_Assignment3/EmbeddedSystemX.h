#pragma once

#include "Mode.h"
#include "PowerOnSelfTest.h"
#include "Initializing.h"
//#include "Operational.h"
//#include "Failure.h"



class EmbeddedSystemX
{
public:
	EmbeddedSystemX();
	void selfTestOK();
	void initialized();
	void startInitializing();
	void restart();
	void configure();
	void configurationEnded();
	void exitStateMachine();
	void stop();
	void start();
	void suspend();
	void resume();
	void selfTestFailed(int);
	void configX();
	void readConfigurationInfo();
	void eventX();
	void eventY();
	void chMode(Mode* state);

private:
	Mode* mode_;
	int versionNo_;
	char* name_;

	friend class Mode;

};

