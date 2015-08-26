#pragma once
#include "UIElement.h"
#include "UIElementFactory.h"
#include "UIDisplaysFactory.h"

class UI
{
public:
	UI();
	virtual ~UI();
	virtual void Update(const double& deltaTime);
	virtual void Render(const unsigned& screenX, const unsigned& screenY);
	virtual void OnTransition();

private:
	UIElementFactory elementFactory;
	UIDisplaysFactory displaysFactory;
};