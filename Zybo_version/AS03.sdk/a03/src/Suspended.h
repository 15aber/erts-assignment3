#pragma once
#include "Operational.h"

#include "xgpio.h"

class Suspended :
	public Operational
{
public:
	static Mode* getInstance();

	void stop(EmbeddedSystemX*) override;
	void resume(EmbeddedSystemX*) override;

private:
	static Mode* instance_;
};

