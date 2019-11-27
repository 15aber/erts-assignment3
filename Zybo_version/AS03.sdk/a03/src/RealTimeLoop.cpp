#include "RealTimeLoop.h"
#include "Ready.h"
#include "Suspended.h"

Mode* RealTimeLoop::instance_ = 0;

Mode* RealTimeLoop::getInstance()
{
	XGpio led;
	XGpio_Initialize(&led, XPAR_LEDS_DEVICE_ID);
	if (instance_ == 0)
	{
		instance_ = new RealTimeLoop();
	}
	xil_printf("\nEntering RealTimeLoop state\r\n");
	xil_printf("\n-- 3 -- For \"suspend\"\r\n");
	xil_printf("-- 5 -- For \"stop\"\r\n");
	xil_printf("-- 0 -- For \"restart\"\r\n");
	XGpio_DiscreteWrite(&led, 1, 0b110);
	return instance_;
}

void RealTimeLoop::stop(EmbeddedSystemX* esx)
{
	xil_printf("RealTimeLoop: Stop\r\n");
	chMode(esx, Ready::getInstance());
}

void RealTimeLoop::suspend(EmbeddedSystemX* esx)
{
	xil_printf("RealTimeLoop: Suspend\r\n");
	chMode(esx, Suspended::getInstance());
}
