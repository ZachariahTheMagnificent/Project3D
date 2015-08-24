#include "UI.h"
#include <iostream>

UI::UI()
{
}

UI::~UI()
{
}

void UI::Update(const double& deltaTime)
{
	elementFactory.UpdateAllElements(deltaTime);
}

UIElementFactory& UI::GetFactory()
{
	return elementFactory;
}