#pragma once

class Trigger
{
public:
	Trigger();
	virtual ~Trigger();

	virtual bool HasTriggered() = 0;
};