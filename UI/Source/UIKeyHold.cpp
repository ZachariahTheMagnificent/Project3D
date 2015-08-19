#include "UIKeyHold.h"

UIKeyHold::UIKeyHold(Keyboard*const kbd)
	:
UIKey(kbd)
{
}

UIKeyHold::~UIKeyHold()
{
}

bool UIKeyHold::HasTriggered()
{
	return kbd->IsKeyHold(key);
}