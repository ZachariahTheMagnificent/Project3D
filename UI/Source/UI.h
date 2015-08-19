#pragma once

class UI
{
public:
	UI();
	~UI();
	virtual UI* Update(const double& deltaTime) = 0;
};