#include "EmbeddedSystemX.h"


void EmbeddedSystemX::selfTestOK()
{
	mode_->selfTestOk(this);
}

void EmbeddedSystemX::initialized()
{
	mode_->initialized(this);
}

void EmbeddedSystemX::restart()
{
	mode_->restart(this);
}

void EmbeddedSystemX::configure()
{
	mode_->configure(this);
}

void EmbeddedSystemX::configurationEnded()
{
	mode_->configurationEnded(this);
}

void EmbeddedSystemX::exit()
{
	mode_->exit(this);
}

void EmbeddedSystemX::stop()
{
	mode_->stop(this);
}

void EmbeddedSystemX::start()
{
	mode_->start(this);
}

void EmbeddedSystemX::suspend()
{
	mode_->suspend(this);
}

void EmbeddedSystemX::resume()
{
	mode_->resume(this);
}

void EmbeddedSystemX::selfTestFailed(int errorNo)
{
	mode_->selfTestFailed(this, errorNo);
}

void EmbeddedSystemX::configX()
{
	mode_->configX(this);
}

void EmbeddedSystemX::chMode(Mode* state)
{
	this->mode_ = state;
}

void EmbeddedSystemX::eventX()
{
}

void EmbeddedSystemX::eventY()
{
}

EmbeddedSystemX::EmbeddedSystemX()
{
	mode_ = PowerOnSelfTest::getInstance();
}
