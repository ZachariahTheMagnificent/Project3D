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

	bool LeftMousePress() const;
	bool RightMousePress() const;

	bool LeftMouseHold() const;
	bool RightMouseHold() const;
	const Vector2& GetPosition() const;

protected:
	bool buttonState[TOTAL_BUTTONS];
	bool buttonStateLastFrame[TOTAL_BUTTONS];
	Vector2 position;
};