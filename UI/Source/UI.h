#pragma once
#include "UIElement.h"
#include "UIElementFactory.h"

class UI
{
public:
	UI();
	virtual ~UI();
	virtual void Update(const double& deltaTime);
	virtual UIElementFactory& GetFactory();

	UIElementFactory elementFactory;
};