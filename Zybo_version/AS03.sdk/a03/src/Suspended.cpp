#include "Suspended.h"
#include "Ready.h"
#include "RealTimeLoop.h"

Mode *Suspended::instance_ = 0;

Mode *Suspended::getInstance()
{
	XGpio led;
	XGpio_Initialize(&led, XPAR_LEDS_DEVICE_ID);
	if (instance_ == 0)
	{
		instance_ = new Suspended();
	}
	xil_printf("\nEntering Suspended state\r\n");
	xil_printf("\n-- 4 -- For \"resume\"\r\n");
	xil_printf("-- 5 -- For \"stop\"\r\n");
	xil_printf("-- 0 -- For \"restart\"\r\n");
	XGpio_DiscreteWrite(&led, 1, 0b111);
	return instance_;
}

void Suspended::stop(EmbeddedSystemX *esx)
{
	xil_printf("Suspended: Stop\r\n");
	chMode(esx, Ready::getInstance());
}

void Suspended::resume(EmbeddedSystemX *esx)
{
	xil_printf("Suspended: Resume\r\n");
	chMode(esx, RealTimeLoop::getInstance());
}
