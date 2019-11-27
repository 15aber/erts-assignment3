#pragma once
#include "Operational.h"

#include "xgpio.h"

class Ready :
	public Operational
{
public:
	static Mode* getInstance();
	
	void start(EmbeddedSystemX*) override;
	void configure(EmbeddedSystemX*) override;
	
private:
	static Mode* instance_;
};

