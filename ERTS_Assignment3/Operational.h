#pragma once
#include "Mode.h"
class Operational :
	public Mode
{
public:
	void restart(EmbeddedSystemX*) override;
};



