#include "Configuration.h"
#include <iostream>

Mode* Configuration::instance_ = 0;

Mode* Configuration::getInstance()
{	
	if(instance_ == 0)
	{
		instance_ = new Configuration();
	}
	std::cout << "Entering Configuration state" << std::endl;
	return instance_;
}

void Configuration::configurationEnded(EmbeddedSystemX* esx)
{
	std::cout << "Configuration: Configuration Ended." << std::endl;
	chMode(esx, Ready::getInstance());
}

void Configuration::readConfigurationInfo(EmbeddedSystemX* esx)
{
	std::cout << "Configuration: Reading Configuration Info." << std::endl;
}

void Configuration::configX(EmbeddedSystemX* esx)
{
	std::cout << "Configuration: Performing Configuration X..." << std::endl;
}

Configuration::Configuration()
{
}
