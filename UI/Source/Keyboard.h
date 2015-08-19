#pragma once
class Keyboard
{
public:
	Keyboard();
	~Keyboard();

	virtual bool IsKeyPressed(const unsigned short& key) = 0;
	virtual bool IsKeyHold(const unsigned short& key) = 0;
	virtual char GetKeyboardBuffer() = 0;
	virtual void UpdateInput() = 0;
};