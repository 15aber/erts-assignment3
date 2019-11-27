/*
 * Empty C++ Application

 */

#include "EmbeddedSystemX.h"
#include "Command.h"

#include "xparameters.h"
#include "xgpio.h"
#include "xgpiops.h"

static XGpioPs psGpioInstancePtr;
static int iPinNumber = 7; /*Led LD9 on ZedBoard and LD4 on Zybo is connected to MIO pin 7*/

int main()
{
	XGpio sw, led;
	int i, pshb_check, sw_check;
	XGpioPs_Config *GpioConfigPtr;
	int xStatus;
	int iPinNumberEMIO = 54;
	u32 uPinDirectionEMIO = 0x0;
	u32 uPinDirection = 0x1;

	// AXI GPIO switches Intialization
	XGpio_Initialize(&sw, XPAR_SWITCHES_DEVICE_ID);

	// AXI GPIO leds Intialization
	XGpio_Initialize(&led, XPAR_LEDS_DEVICE_ID);

	// PS GPIO Intialization
	GpioConfigPtr = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);
	if (GpioConfigPtr == NULL)
		return XST_FAILURE;
	xStatus = XGpioPs_CfgInitialize(&psGpioInstancePtr,
									GpioConfigPtr,
									GpioConfigPtr->BaseAddr);

	if (XST_SUCCESS != xStatus)
		print(" PS GPIO INIT FAILED \n\r");
	//PS GPIO pin setting to Output
	XGpioPs_SetDirectionPin(&psGpioInstancePtr, iPinNumber, uPinDirection);
	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, iPinNumber, 1);

	//EMIO PIN Setting to Input port
	XGpioPs_SetDirectionPin(&psGpioInstancePtr, iPinNumberEMIO, uPinDirectionEMIO);
	XGpioPs_SetOutputEnablePin(&psGpioInstancePtr, iPinNumberEMIO, 0);

	// Configure the entry
	Command *start = new StartCommand;
	Command *configure = new ConfigureCommand;
	Command *configurationEnded = new ConfigurationEndedCommand;
	Command *stop = new StopCommand;
	Command *suspend = new SuspendCommand;
	Command *resume = new ResumeCommand;
	Command *readConfigurationInfo = new ReadConfigurationInfoCommand;
	Command *configX = new ConfigXCommand;

	xil_printf("-- Welcome to assignment 3!! --\r\n");

	EmbeddedSystemX esx;
	esx.restart();
	esx.systemSelfTest();
	esx.startInitializing();

	while (1)
	{
		pshb_check = XGpioPs_ReadPin(&psGpioInstancePtr, iPinNumberEMIO);
		if (pshb_check)
		{
			sw_check = XGpio_DiscreteRead(&sw, 1);
			while (pshb_check)
			{
				pshb_check = XGpioPs_ReadPin(&psGpioInstancePtr, iPinNumberEMIO);
			}
			
			switch (sw_check)
			{
			case 1:
				esx.handleCommand(configure);
				esx.handleCommand(readConfigurationInfo);
				esx.handleCommand(configX);
				esx.handleCommand(configurationEnded);
				break;
			case 2:
				esx.handleCommand(start);
				break;
			case 3:
				esx.handleCommand(suspend);
				break;
			case 4:
				esx.handleCommand(resume);
				break;
			case 5:
				esx.handleCommand(stop); /* code */
				break;
			case 0:
				esx.restart();
			
			default:
				break;
			}
		}
	}

	return 0;
}
