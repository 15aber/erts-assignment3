#include "PowerOnSelfTest.h"


int test = 0;

Mode *PowerOnSelfTest::instance_ = 0;

Mode *PowerOnSelfTest::getInstance()
{
	XGpio led;
	XGpio_Initialize(&led, XPAR_LEDS_DEVICE_ID);
	if (instance_ == 0)
	{
		instance_ = new PowerOnSelfTest();
		// AXI GPIO leds Intialization
	}
	
	xil_printf("\nEntering PowerOnSelfTest state\r\n");
	XGpio_DiscreteWrite(&led, 1, 0b01);
	return instance_;
}

void PowerOnSelfTest::selfTestFailed(EmbeddedSystemX *esx, int ErrorNo)
{
	xil_printf("PowerOnSelfTest: SelfTestFailed\r\n");
	chMode(esx, Failure::getInstance());
}

void PowerOnSelfTest::selfTestOk(EmbeddedSystemX *esx)
{
	xil_printf("PowerOnSelfTest: SelfTest OK\r\n");

	chMode(esx, Initializing::getInstance());
}

void PowerOnSelfTest::systemSelfTest(EmbeddedSystemX *esx)
{
	xil_printf("PowerOnSelfTest: Running System Self Test...\r\n");

	if ((++test) % 2 == 0)
		selfTestOk(esx);
	else
		selfTestFailed(esx, 1);
}

PowerOnSelfTest::PowerOnSelfTest() = default;
