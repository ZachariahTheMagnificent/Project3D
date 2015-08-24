#pragma once
#include "UIElement.h"
#include "UIElementFactory.h"

class UI
{
public:
	UI();
	virtual ~UI();
	virtual void Update(const double& deltaTime);
	virtual UIElement* AddElement();

	UIElementFactory elementFactory;
};