#include "GLMouse.h"
/****************************************************************************/
/*!
\file GLMouse.cpp
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class that handles mouse input
*/
/****************************************************************************/

/****************************************************************************/
/*!
\brief
Constructor that specifies the current window
\param m_window
		gives the GLMouse object our current window
*/
/****************************************************************************/
GLMouse::GLMouse(GLFWwindow* m_window)
{
	InitWindow(m_window);
}
/****************************************************************************/
/*!
\brief
Initializes the GLMouse object to our current window
*/
/****************************************************************************/
void GLMouse::InitWindow(GLFWwindow* window)
{
	m_window = window;
}
/****************************************************************************/
/*!
\brief
Default destructor
*/
/****************************************************************************/
GLMouse::~GLMouse()
{
}
/****************************************************************************/
/*!
\brief
returns the current mouse displacement from the centre then locks it to the centre
\param destX
		a reference to a variable where we store the X displacement
\param destY
		a reference to a variable where we store the Y displacement
*/
/****************************************************************************/
void GLMouse::Update()
{
	double mouseX;
	double mouseY;

	glfwGetCursorPos(m_window, &mouseX, &mouseY);
	position.Set(mouseX, mouseY);

	int width;
	int height;

	glfwGetWindowSize(m_window, &width, &height);
	centre.Set(width/2, height/2);

	if(fixedmouse)
	{
		SetToCentre();
	}
}
/****************************************************************************/
/*!
\brief
Sets the mouse to the centre of the screen
*/
/****************************************************************************/
void GLMouse::SetToCentre()
{
	glfwSetCursorPos(m_window, centre.x, centre.y);	
}