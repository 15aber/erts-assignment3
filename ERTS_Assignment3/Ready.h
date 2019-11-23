#pragma once
#include "Operational.h"
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

