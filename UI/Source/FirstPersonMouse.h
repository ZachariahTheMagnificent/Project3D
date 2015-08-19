#pragma once
#include "Mouse.h"

class FirstPersonMouse : public Mouse
{
public:
	FirstPersonMouse();
	~FirstPersonMouse();
	virtual void Update() = 0;
	virtual void SetToCentre() = 0;

	Vector2 GetDisplacementFromCentre();

protected:
	Vector2 centre;
	bool fixedmouse;
};

