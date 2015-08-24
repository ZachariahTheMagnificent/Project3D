#pragma once
#include "UI.h"

class UIMain : public UI
{
public:
	UIMain();
	virtual ~UIMain();

	void Update(const double& deltaTime);
};