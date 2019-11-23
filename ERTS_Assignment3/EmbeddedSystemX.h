#pragma once

#include "Mode.h"
#include "PowerOnSelfTest.h"
//#include "Initializing.h"
//#include "Operational.h"
//#include "Failure.h"



class EmbeddedSystemX
{
	Mode* mode_;

public:
	void selfTestOK();
	void initialized();
	void restart();
	void configure();
	void configurationEnded();
	void exit();
	void stop();
	void start();
	void suspend();
	void resume();
	void selfTestFailed(int);
	void configX();
	void eventX();
	void eventY();
	void chMode(Mode* state);

	static EmbeddedSystemX* getInstance();

protected:
	EmbeddedSystemX();

private:
	int versionNo_;
	char* name_;


	friend class Mode;
	static EmbeddedSystemX* instance_;

};

