#include "Failure.h"


Mode* Failure::instance_ = 0;

Mode* Failure::getInstance()
{	
	XGpio led;
	XGpio_Initialize(&led, XPAR_LEDS_DEVICE_ID);
	if(instance_ == 0)
	{
		instance_ = new Failure();
	}
	xil_printf("\nEntering Failure state\r\n");
	XGpio_DiscreteWrite(&led, 1, 0b10);
	return instance_;
}


void Failure::restart(EmbeddedSystemX* esx)
{
	xil_printf("Failure: restarting\r\n");
	chMode(esx, PowerOnSelfTest::getInstance());
}

void Failure::exitStateMachine(EmbeddedSystemX* esx)
{
	xil_printf("Failure: Leaving the program\r\n");
	//TODO: Implement Exit
	//exit(0);
}

void Failure::display(EmbeddedSystemX* esx, int ErrorNo)
{
	//TODO: cast of type int to char8
	//"Failure: Error No: " << ErrorNo << " encountered."
	xil_printf("Failure: Error encounter\r\n");
	restart(esx);
	//exitStateMachine(esx);
}

Failure::Failure()
{
}

