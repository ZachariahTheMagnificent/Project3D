#include "UIButton.h"

UIButton::UIButton()
{
}

UIButton::~UIButton()
{
}

bool UIButton::HasTriggered()
{
	return mouse->LeftMousePress();
}