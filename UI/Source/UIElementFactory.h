#pragma once
#include "UIElement.h"
#include "Factory.h"
#include "UIButton.h"
#include "UIDataClient.h"

class UIElementFactory : public Factory<UIElement>
{
public:
	UIElementFactory();
	virtual ~UIElementFactory();
	
	virtual UIElement* GetInstance(unsigned type);
	virtual void UpdateAllElements();
};