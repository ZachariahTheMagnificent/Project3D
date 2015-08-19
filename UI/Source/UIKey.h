#pragma once
#include "UIElement.h"
#include "Trigger.h"
#include "Keyboard.h"

class UIKey : public UIElement, public Trigger
{
public:
	UIKey(Keyboard*const kbd);
	~UIKey();
	virtual bool HasTriggered() = 0;
	
	char key;
protected:
	Keyboard* kbd;
};