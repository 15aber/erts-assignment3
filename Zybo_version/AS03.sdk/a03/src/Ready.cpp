#include "Ready.h"
#include "RealTimeLoop.h"
#include "Configuration.h"

Mode* Ready::instance_ = 0;

Mode* Ready::getInstance()
{
	XGpio led;
	XGpio_Initialize(&led, XPAR_LEDS_DEVICE_ID);
	if (instance_ == 0)
	{
		instance_ = new Ready();
	}
	xil_printf("\nEntering Ready state\r\n");
	xil_printf("\n-- 1 -- For \"configure\"\r\n");
	xil_printf("-- 2 -- For \"start\"\r\n");
	xil_printf("-- 0 -- For \"restart\"\r\n");
	XGpio_DiscreteWrite(&led, 1, 0b111);
	return instance_;
}


void Ready::start(EmbeddedSystemX* esx)
{
	xil_printf("\nReady: Start\r\n");

	chMode(esx, RealTimeLoop::getInstance());
}

void Ready::configure(EmbeddedSystemX* esx)
{
	xil_printf("\nReady: Configure\r\n");
	chMode(esx, Configuration::getInstance());
}
