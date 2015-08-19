#pragma once

class Trigger
{
public:
	Trigger();
	~Trigger();
	virtual bool HasTriggered() = 0;
};