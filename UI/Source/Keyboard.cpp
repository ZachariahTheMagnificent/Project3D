#include "Keyboard.h"

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
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
bool Keyboard::IsKeyHold(const unsigned short& key)
{
	return keyishold[key];
}
/****************************************************************************/
/*!
\brief
Returns if a key is pressed once and won't return true again until the key is released and pressed again
\param key
		the key to be checked
*/
/****************************************************************************/
bool Keyboard::IsKeyPressed(const unsigned short& key)
{
	return keyispressed[key];
}
/****************************************************************************/
/*!
\brief
Returns the last key stored in the keyboard's buffer then deletes it from the buffer(for keyboard input)
*/
/****************************************************************************/
char Keyboard::GetKeyboardBuffer()
{
	if(keyboardbuffer.empty())
	{
		return 0;
	}
	else
	{
		char letter = keyboardbuffer.front();
		keyboardbuffer.pop();
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
bool Keyboard::IsKeyReleased(const unsigned short& key)
{
	return !(IsKeyHold(key));
}