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

void FirstPersonMouse::ToggleLock()
{
	fixedmouse != fixedmouse;
}

void FirstPersonMouse::LockMouse()
{
	fixedmouse = true;
}

void FirstPersonMouse::UnlockMouse()
{
	fixedmouse = false;
}

bool FirstPersonMouse::IsLocked() const
{
	return fixedmouse;
}