#pragma once
#include "Factory.h"
#include "ProductionLine.h"

class UIElementFactory : public Factory
{
public:
	UIElementFactory();
	virtual ~UIElementFactory();
	
	//virtual UIText* GetText();
	//virtual UIImage* GetImage();
	virtual void UpdateAllElements(const double& deltaTime);

private:
	//ProductionLine<UIText> textProduction;
	//ProductionLine<UIImage> imageProduction;
};