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
	void UpdateInput();
private:
	bool GetKey(const unsigned short& key);
};