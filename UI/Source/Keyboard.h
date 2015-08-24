#pragma once
#include <queue>

class Keyboard
{
public:
	Keyboard();
	~Keyboard();

	virtual bool IsKeyPressed(const unsigned short& key);
	virtual bool IsKeyHold(const unsigned short& key);
	virtual char GetKeyboardBuffer();
	bool IsKeyReleased(const unsigned short& key);
	virtual void UpdateInput() = 0;

	std::queue<char> keyboardbuffer;
	bool keyAlreadyPressed[256];
	bool keyispressed[256];
	bool keyishold[256];
};