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
	elementFactory.UpdateAllElements();
}

UIElement* UI::AddElement()
{
	return elementFactory.GetInstance(1);
}