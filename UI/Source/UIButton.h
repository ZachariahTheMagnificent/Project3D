#pragma once
#include "UIElement.h"
#include "Trigger.h"
#include "Mouse.h"

class UIButton : public Trigger
{
public:
	UIButton(const Mouse* mouse);
	virtual ~UIButton();
	
	virtual UIBox GetBoundingBox() const = 0;

	virtual bool HasTriggered();

	UIElement* normalElement;
	UIElement* hoverElement;

private:
	const Mouse* mouse;
};