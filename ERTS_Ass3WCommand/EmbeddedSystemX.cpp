#include "EmbeddedSystemX.h"
#include <iostream>




void EmbeddedSystemX::selfTestOK()
{
	mode_->selfTestOk(this);
}

void EmbeddedSystemX::initialized()
{
	mode_->initialized(this);
}

void EmbeddedSystemX::startInitializing()
{
	mode_->startInitializing(this);
}

void EmbeddedSystemX::restart()
{
	mode_->restart(this);
}

void EmbeddedSystemX::exitStateMachine()
{
	mode_->exitStateMachine(this);
}

void EmbeddedSystemX::systemSelfTest()
{
	mode_->systemSelfTest(this);
}

void EmbeddedSystemX::selfTestFailed(int errorNo)
{
	mode_->selfTestFailed(this, errorNo);
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

EmbeddedSystemX::EmbeddedSystemX(): versionNo_(1)
{
	std::cout << "EmbeddedSystemX: Created. Version number: "<< versionNo_ << std::endl;
	std::cout << "Mode set to: PowerOnSelfTest" << std::endl;
	mode_ = PowerOnSelfTest::getInstance();
	mode_->systemSelfTest(this);
}

void EmbeddedSystemX::handleCommand(Command* c) 
{
	c->execute(this, mode_);
}
