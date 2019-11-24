#pragma once
#include "Operational.h"
#include "Ready.h"
class Configuration :
	public Operational
{
public:
	static Mode* getInstance();

	void configurationEnded(EmbeddedSystemX*) override;

	void readConfigurationInfo(EmbeddedSystemX*) override; //own
	void configX(EmbeddedSystemX*) override; //own

protected:
	Configuration();

private:
	static Mode* instance_;

};

