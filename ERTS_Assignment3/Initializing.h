#pragma once
#include "Mode.h"
class Initializing :
	public Mode
{
public:
	static Mode* getInstance();

	void initialized(EmbeddedSystemX*) override;

	void startInitializing(); //own
protected:
	Initializing();

private:
	static Mode* instance_;
};

