#include "UIButton.h"
#include <iostream>

UIButton::UIButton(const Mouse* mouse)
	:
mouse(mouse),
normalElement(NULL),
hoverElement(NULL),
activeElement(NULL)
{
}

UIButton::~UIButton()
{
}

void UIButton::UpdateActiveElement()
{
	if(GetBoundingBox().IsInside(mouse->GetPosition()) && hoverElement)
	{
		activeElement = hoverElement;
	}
}

UIBox UIButton::GetBoundingBox()
{
	if(activeElement)
	{
		return activeElement->GetBoundingBox();
	}

	return UIBox();
}

bool UIButton::HasTriggered()
{
	return GetBoundingBox().IsInside(mouse->GetPosition()) && mouse->LeftMousePress() && active;
}