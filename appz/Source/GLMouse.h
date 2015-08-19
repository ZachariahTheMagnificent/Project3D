#pragma once
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "FirstPersonMouse.h"
/****************************************************************************/
/*!
\file GLMouse.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class that handles mouse input
*/
/****************************************************************************/

/****************************************************************************/
/*!
Class GLMouse:
\brief
handles mouse input
*/
/****************************************************************************/
class GLMouse : public FirstPersonMouse
{
public:
	GLMouse(GLFWwindow* m_window = NULL);
	~GLMouse();
	void InitWindow(GLFWwindow* window);
	void Update();
	void SetToCentre();
private:
	GLFWwindow* m_window;
};

