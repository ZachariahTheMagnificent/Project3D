#pragma once
#include "UIKey.h"

class UIKeyPress : public UIKey
{
public:
	UIKeyPress(Keyboard* kbd);
	~UIKeyPress();
	virtual bool HasTriggered();
};