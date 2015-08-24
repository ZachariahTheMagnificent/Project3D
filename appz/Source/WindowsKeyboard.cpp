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
	//clear the buffer
	keyboardbuffer.swap(std::queue<char>());
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
	for(unsigned index = ' '; index < '~'; index++)
	{
		if(IsKeyPressed(index))
		{
			keyboardbuffer.push((char)index);
		}
	}
}