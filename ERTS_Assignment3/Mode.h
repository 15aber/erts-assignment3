#pragma once
#include "EmbeddedSystemX.h"

class EmbeddedSystemX;

class Mode
{
public:
	virtual	void selfTestFailed(EmbeddedSystemX*, int errorNo);
	virtual void selfTestOk(EmbeddedSystemX*);
	//virtual void systemSelfTest(EmbeddedSystemX*);
	virtual void initialized(EmbeddedSystemX*);
	virtual void exit(EmbeddedSystemX*);
	virtual void restart(EmbeddedSystemX*);
	virtual void display(EmbeddedSystemX*, int errorNo);
	virtual void start(EmbeddedSystemX*);
	virtual void configure(EmbeddedSystemX*);
	virtual void configuratoinEnded(EmbeddedSystemX*);
	virtual void configX(EmbeddedSystemX*);
	virtual void stop(EmbeddedSystemX*);
	virtual void suspend(EmbeddedSystemX*);
	virtual void resume(EmbeddedSystemX*);

protected:
	void chMode(EmbeddedSystemX*, Mode*);
	Mode() {};

private:

};

