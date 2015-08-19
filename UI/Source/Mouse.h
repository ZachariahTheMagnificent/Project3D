#pragma once
#include "Vector2.h"

class Mouse
{
public:
	enum BUTTONS
	{
		LEFT,
		RIGHT,
		TOTAL_BUTTONS
	};

	Mouse();
	~Mouse();
	virtual void Update() = 0;

	bool LeftMousePress();
	bool RightMousePress();

	bool LeftMouseHold();
	bool RightMouseHold();
	const Vector2& GetPosition();

protected:
	bool buttonState[TOTAL_BUTTONS];
	bool buttonStateLastFrame[TOTAL_BUTTONS];
	Vector2 position;
};