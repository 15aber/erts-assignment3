#include "Initializing.h"

void Initializing::initialize()
{
}

Mode* Initializing::instance_ = 0;

Mode* Initializing::getInstance()
{
	if (instance_ == 0)
	{
		instance_ = new Initializing();
	}
	return instance_; 
}
