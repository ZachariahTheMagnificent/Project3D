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

void UI::Render(const unsigned& screenX, const unsigned& screenY)
{
	Mtx44 projection;
	const unsigned depth = 100;
	projection.SetToOrtho(0, screenX, 0, screenY, -depth, depth);
	displaysFactory.Render(projection);
}

void UI::OnTransition()
{
}