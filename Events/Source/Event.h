#pragma once
#include "Trigger.h"

class Event
{
public:
	Event();
	virtual ~Event();

	virtual void Update(const double& deltaTime) = 0;
	virtual void OnTrigger() = 0;
	virtual bool IsActive();
	
	Trigger* trigger;
};