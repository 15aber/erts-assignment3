#pragma once
class EmbeddedSystemX;
class Mode;

class Command
{
public:
	virtual ~Command() = default;

	virtual void execute(EmbeddedSystemX* pESX, Mode* pMode) = 0;

protected:
	Command() = default;
};

class ConfigXCommand : public Command
{
public:
	void execute(EmbeddedSystemX* pESX, Mode* pMode) override;
};

class ReadConfigurationInfoCommand : public Command
{
public:
	void execute(EmbeddedSystemX* pESX, Mode* pMode) override;
};


class StartCommand : public Command
{
public:
	void execute(EmbeddedSystemX* pESX, Mode* pMode) override;
};

class ConfigureCommand : public Command
{
public:
	void execute(EmbeddedSystemX* pESX, Mode* pMode) override;
};

class ConfigurationEndedCommand : public Command
{
public:
	void execute(EmbeddedSystemX* pESX, Mode* pMode) override;
};

class StopCommand : public Command// todo error no
{
public:
	void execute(EmbeddedSystemX* pESX, Mode* pMode) override;
};

class SuspendCommand : public Command
{
public:
	void execute(EmbeddedSystemX* pESX, Mode* pMode) override;
};

class ResumeCommand : public Command
{
public:
	void execute(EmbeddedSystemX* pESX, Mode* pMode) override;
};