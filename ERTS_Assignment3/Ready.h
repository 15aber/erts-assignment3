#pragma once
#include "Operational.h"
class Ready :
	public Operational
{
public:
	void start(EmbeddedSystemX*) override;
	void configure(EmbeddedSystemX*) override;
};

