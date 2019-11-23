#pragma once
#include "Mode.h"
#include "PowerOnSelfTest.h"
class Failure:
	public Mode
{
public:
	static Mode* getInstance();

	void restart(EmbeddedSystemX*) override;

	void display(EmbeddedSystemX* esx, int ErrorNo); //own
protected:
	Failure();
private:
	static Mode* instance_;
};

