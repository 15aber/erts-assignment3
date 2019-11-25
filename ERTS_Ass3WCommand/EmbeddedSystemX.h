#pragma once

#include "Mode.h"
#include "Command.h"
#include "PowerOnSelfTest.h"
#include "Initializing.h"
//#include "Operational.h"
//#include "Failure.h"



class EmbeddedSystemX
{
public:
	EmbeddedSystemX();

	void handleCommand(Command*);
	
	void selfTestOK();
	void initialized();
	void startInitializing();
	void restart();
	void exitStateMachine();
	void systemSelfTest();
	void selfTestFailed(int);
	void eventX();
	void eventY();
	void chMode(Mode* state);

private:
	Mode* mode_;
	int versionNo_;
	char* name_;

	friend class Mode;

};

