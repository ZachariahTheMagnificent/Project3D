#include "UIKeyPress.h"

UIKeyPress::UIKeyPress(Keyboard* kbd)
	:
UIKey(kbd)
{
}

UIKeyPress::~UIKeyPress()
{
}

bool UIKeyPress::HasTriggered()
{
	return kbd->IsKeyPressed(key);
}