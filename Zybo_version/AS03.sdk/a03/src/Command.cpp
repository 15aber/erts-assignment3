#include "Mode.h"
#include "EmbeddedSystemX.h"
#include "Command.h"



void StartCommand::execute(EmbeddedSystemX* pESX, Mode* pMode)
{
	pMode->start(pESX);
}

void ConfigureCommand::execute(EmbeddedSystemX* pESX, Mode* pMode)
{
	pMode->configure(pESX);
}


void ConfigurationEndedCommand::execute(EmbeddedSystemX* pESX, Mode* pMode)
{
	pMode->configurationEnded(pESX);
}

void StopCommand::execute(EmbeddedSystemX* pESX, Mode* pMode)
{
	pMode->stop(pESX); 
}

void SuspendCommand::execute(EmbeddedSystemX* pESX, Mode* pMode)
{
	pMode->suspend(pESX);
}

void ResumeCommand::execute(EmbeddedSystemX* pESX, Mode* pMode)
{
	pMode->resume(pESX);
}

void ConfigXCommand::execute(EmbeddedSystemX* pESX, Mode* pMode)
{
	pMode->configX(pESX);
}

void ReadConfigurationInfoCommand::execute(EmbeddedSystemX* pESX, Mode* pMode)
{
	pMode->readConfigurationInfo(pESX);
}