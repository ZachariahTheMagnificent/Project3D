#pragma once
#include "event.h"
class SpawnEvent :
	public Event
{
public:
	SpawnEvent(void);
	~SpawnEvent(void);

	virtual void Update(const double& deltaTime);
	virtual void OnTrigger();
};

