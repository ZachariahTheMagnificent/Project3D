#include "UIButton.h"
#include <iostream>

UIButton::UIButton(const Mouse* mouse)
	:
mouse(mouse),
normalElement(NULL),
hoverElement(NULL)
{
}

UIButton::~UIButton()
{
}

bool UIButton::HasTriggered()
{
	return GetBoundingBox().IsInside(mouse->GetPosition()) && mouse->LeftMousePress();
}