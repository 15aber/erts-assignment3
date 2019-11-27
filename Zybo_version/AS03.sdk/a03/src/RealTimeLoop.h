#pragma once
#include "Operational.h"

#include "xgpio.h"

class RealTimeLoop :
	public Operational
{
public:
	static Mode* getInstance();

	void stop(EmbeddedSystemX*) override;
	void suspend(EmbeddedSystemX*) override;

private:
	static Mode* instance_;
	
};

