#pragma once
#include "Operational.h"
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

