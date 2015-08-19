#include "FirstPersonMouse.h"

FirstPersonMouse::FirstPersonMouse()
	:
fixedmouse(false)
{
}

FirstPersonMouse::~FirstPersonMouse()
{
}

Vector2 FirstPersonMouse::GetDisplacementFromCentre()
{
	return position - centre;
}