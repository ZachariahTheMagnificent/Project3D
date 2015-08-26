#pragma once
#include "UIElement.h"
#include "UIDisplays.h"
#include "Mouse.h"

class UIButton : public UIElement
{
public:
	UIButton(const Mouse* mouse);
	virtual ~UIButton();

	virtual void Update(const double& deltaTime) = 0;

	void UpdateActiveElement();
	UIBox GetBoundingBox();
	bool HasTriggered();

	UIDisplays* normalElement;
	UIDisplays* hoverElement;
	UIDisplays* activeElement;
private:
	const Mouse* mouse;
};