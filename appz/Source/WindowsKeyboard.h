#pragma once
/****************************************************************************/
/*!
\file Keyboard.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class that handles keyboard input
*/
/****************************************************************************/
#include <vector>
#include <Windows.h>
#include "Keyboard.h"
/****************************************************************************/
/*!
Class Keyboard:
\brief
handles keyboard input
*/
/****************************************************************************/
class WindowsKeyboard : public Keyboard
{
public:
	WindowsKeyboard();
	~WindowsKeyboard();
	bool IsKeyPressed(const unsigned short& key);
	bool IsKeyHold(const unsigned short& key);
	char GetKeyboardBuffer();
	void UpdateInput();
private:
	bool IsKeyReleased(const unsigned short& key);
	bool GetKey(const unsigned short& key);
	std::vector<char> keyboardbuffer;
	bool keyAlreadyPressed[256];
	bool keyispressed[256];
	bool keyishold[256];
};