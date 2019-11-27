#include "Initializing.h"
#include "Ready.h"

Mode *Initializing::instance_ = 0;

Mode *Initializing::getInstance()
{
	XGpio led;
	XGpio_Initialize(&led, XPAR_LEDS_DEVICE_ID);
	if (instance_ == 0)
	{
		instance_ = new Initializing();
	}
	xil_printf("\nEntering Initializing state\r\n");
	XGpio_DiscreteWrite(&led, 1, 0b11);
	return instance_;
}

void Initializing::initialized(EmbeddedSystemX *esx)
{
	xil_printf("Initializing: Initialized\r\n");
	chMode(esx, Ready::getInstance());
}

void Initializing::startInitializing(EmbeddedSystemX *esx)
{
	xil_printf("Initializing: Start Initializing\r\n");
	initialized(esx);
}

Initializing::Initializing()
{
}
