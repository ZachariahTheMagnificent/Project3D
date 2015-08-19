#include "Mouse.h"

Mouse::Mouse()
{
	bool* end = buttonState + TOTAL_BUTTONS;
	for(bool* state = buttonState; state != end; ++state)
	{
		*buttonState = false;
	}

	end = buttonStateLastFrame + TOTAL_BUTTONS;
	for(bool* state = buttonStateLastFrame; state != end; ++state)
	{
		*buttonState = false;
	}
}

Mouse::~Mouse()
{
}

bool Mouse::LeftMousePress()
{
	return buttonState[LEFT] && !buttonStateLastFrame[LEFT];
}

bool Mouse::RightMousePress()
{
	return buttonState[RIGHT] && !buttonStateLastFrame[RIGHT];
}

bool Mouse::LeftMouseHold()
{
	return buttonState[LEFT];
}

bool Mouse::RightMouseHold()
{
	return buttonState[RIGHT];
}

const Vector2& Mouse::GetPosition()
{
	return position;
}