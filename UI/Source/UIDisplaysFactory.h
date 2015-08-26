#pragma once
#include "UIMesh.h"
#include "UIText.h"
#include "UIImage.h"
#include "Factory.h"
#include "ProductionLine.h"

class UIDisplaysFactory : public Factory
{
public:
	UIDisplaysFactory();
	virtual ~UIDisplaysFactory();

	void Render(const Mtx44& projection);
	UIMesh* GetMesh();
	UIText* GetText();
	UIImage* GetImage();
private:
	ProductionLine<UIMesh> meshProduction;
	ProductionLine<UIText> textProduction;
	ProductionLine<UIImage> imageProduction;
};