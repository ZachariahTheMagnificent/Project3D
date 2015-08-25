#pragma once
#include "Factory.h"
#include "ProductionLine.h"

class UIElementFactory : public Factory
{
public:
	enum ELEMENT_TYPE
	{
		UI_TEXT,
		UI_IMAGE,
		UI_TRANSITION_BUTTON,
		TOTAL_ELEMENTS
	};
	UIElementFactory();
	virtual ~UIElementFactory();
	
	//virtual UIText* GetText();
	//virtual UIImage* GetImage();
	virtual void UpdateAllElements(const double& deltaTime);

private:
	//ProductionLine<UIText> textProduction;
	//ProductionLine<UIImage> imageProduction;
};