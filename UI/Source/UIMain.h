#pragma once
#include "UI.h"

class UIMain : public UI
{
public:
	UIMain();
	~UIMain();
	UI* Update(const double& deltaTime);
};