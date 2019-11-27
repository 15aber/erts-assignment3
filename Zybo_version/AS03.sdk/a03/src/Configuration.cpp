#include "Configuration.h"

Mode* Configuration::instance_ = 0;

Mode* Configuration::getInstance()
{	
	XGpio led;
	XGpio_Initialize(&led, XPAR_LEDS_DEVICE_ID);
	if(instance_ == 0)
	{
		instance_ = new Configuration();
	}
	
	xil_printf("\nEntering Configuration state\r\n");
	XGpio_DiscreteWrite(&led, 1, 0b101);
	return instance_;
}

void Configuration::configurationEnded(EmbeddedSystemX* esx)
{
	xil_printf("Configuration: Configuration Ended.\r\n");
	chMode(esx, Ready::getInstance());
}

void Configuration::readConfigurationInfo(EmbeddedSystemX* esx)
{
	xil_printf("Configuration: Reading Configuration Info.\r\n");
}

void Configuration::configX(EmbeddedSystemX* esx)
{
	xil_printf("Configuration: Performing Configuration X...\r\n");
}

Configuration::Configuration()
{
}
