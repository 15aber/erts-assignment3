#include "Mode.h"
#include "EmbeddedSystemX.h"

void Mode::selfTestFailed(EmbeddedSystemX*, int errorNo)
{
}

void Mode::selfTestOk(EmbeddedSystemX*)
{
}

void Mode::initialized(EmbeddedSystemX*)
{
}

void Mode::exit(EmbeddedSystemX*)
{
}

void Mode::restart(EmbeddedSystemX*)
{
}

void Mode::display(EmbeddedSystemX*, int errorNo)
{
}

void Mode::start(EmbeddedSystemX*)
{
}

void Mode::configure(EmbeddedSystemX*)
{
}

void Mode::configurationEnded(EmbeddedSystemX*)
{
}

void Mode::configX(EmbeddedSystemX*)
{
}

void Mode::stop(EmbeddedSystemX*)
{
}

void Mode::suspend(EmbeddedSystemX*)
{
}

void Mode::resume(EmbeddedSystemX*)
{
}

void Mode::chMode(EmbeddedSystemX* x, Mode* m)
{
	x->chMode(m);
}

Mode::Mode()
{
}
