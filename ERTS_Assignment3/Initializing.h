#pragma once
#include "Mode.h"
class Initializing :
	public Mode
{
public:
	void initialize();

	static Mode* getInstance();

private:
	static Mode* instance_;
};

