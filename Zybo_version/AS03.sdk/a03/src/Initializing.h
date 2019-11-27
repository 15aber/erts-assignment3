#pragma once
#include "Mode.h"
#include "Operational.h"

#include "xgpio.h"

class Initializing :
	public Mode
{
public:
	static Mode* getInstance();

	void initialized(EmbeddedSystemX*) override;

	void startInitializing(EmbeddedSystemX*); //own
protected:
	Initializing();

private:
	static Mode* instance_;
};

