#pragma once
#include "UIkey.h"

class UIKeyHold : public UIKey
{
public:
	UIKeyHold(Keyboard*const kbd);
	~UIKeyHold();
	virtual bool HasTriggered();
};