#pragma once
#include "Event.h"
#include "UIElement.h"

class UIEvent : public Event
{
public:
	UIEvent();
	virtual ~UIEvent();
	
	virtual void Update(const double& deltaTime) = 0;
	virtual void OnTrigger() = 0;
};