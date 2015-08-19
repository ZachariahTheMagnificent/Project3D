#include "WindowsKeyboard.h"
#include <iostream>
/****************************************************************************/
/*!
\file Keyboard.cpp
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class that handles keyboard input
*/
/****************************************************************************/

/****************************************************************************/
/*!
\brief
Default constructor
*/
/****************************************************************************/
WindowsKeyboard::WindowsKeyboard()
{
}
/****************************************************************************/
/*!
\brief
Default destructor
*/
/****************************************************************************/
WindowsKeyboard::~WindowsKeyboard()
{
}
/****************************************************************************/
/*!
\brief
Returns if a key is pressed
\param key
		the key to be checked
*/
/****************************************************************************/
bool WindowsKeyboard::IsKeyHold(const unsigned short& key)
{
	return keyishold[key];
}
/****************************************************************************/
/*!
\brief
Returns the key state from windows directly
\param key
		the key to be checked
*/
/****************************************************************************/
bool WindowsKeyboard::GetKey(const unsigned short& key)
{
	return ((GetAsyncKeyState(key) & 0x8001) != 0);
}
/****************************************************************************/
/*!
\brief
Updates the keyboard values
*/
/****************************************************************************/
void WindowsKeyboard::UpdateInput()
{
	keyboardbuffer.clear();
	for(int index = 0; index < 256; index++)
	{
		unsigned short keyIsPressed = GetKey(index);
		if(keyAlreadyPressed[index] && !keyIsPressed)
		{
			keyAlreadyPressed[index] = false;
			keyispressed[index] = false;
			keyishold[index] = false;
		}
		else if(!keyAlreadyPressed[index] && keyIsPressed)
		{
			keyAlreadyPressed[index] = true;
			keyispressed[index] = true;
			keyishold[index] = true;
		}
		else if(keyAlreadyPressed[index] && keyIsPressed)
		{
			keyispressed[index] = false;
			keyishold[index] = true;
		}
		else
		{
			keyispressed[index] = false;
			keyishold[index] = false;
		}
	}
	for(int index = ' '; index < '~'; index++)
	{
		if(IsKeyPressed(index))
		{
			keyboardbuffer.push_back((char)index);
		}
	}
}
/****************************************************************************/
/*!
\brief
Returns if a key is pressed once and won't return true again until the key is released and pressed again
\param key
		the key to be checked
*/
/****************************************************************************/
bool WindowsKeyboard::IsKeyPressed(const unsigned short& key)
{
	return keyispressed[key];
}
/****************************************************************************/
/*!
\brief
Returns the last key stored in the keyboard's buffer then deletes it from the buffer(for keyboard input)
*/
/****************************************************************************/
char WindowsKeyboard::GetKeyboardBuffer()
{
	if(keyboardbuffer.empty())
	{
		return 0;
	}
	else
	{
		char letter = keyboardbuffer.back();
		keyboardbuffer.pop_back();
		return letter;
	}
}
/****************************************************************************/
/*!
\brief
Returns if a key that has been previously pressed has been released
\param key
		the key to be checked
*/
/****************************************************************************/
bool WindowsKeyboard::IsKeyReleased(const unsigned short& key)
{
	return !(IsKeyHold(key));
}