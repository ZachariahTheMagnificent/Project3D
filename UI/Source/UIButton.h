#pragma once
#include "UIDisplay.h"
#include "Trigger.h"
#include "Mouse.h"

class UIButton : public UIDisplay, public Trigger
{
public:
	UIButton();
	~UIButton();
	
	virtual bool HasTriggered();

private:
	Mouse* mouse;
};