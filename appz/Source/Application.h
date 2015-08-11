#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "timer.h"
#include "Sound.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "GLMouse.h"

class Application
{
public:
	Application();
	~Application();
	void Init();
	void Run();
	void Exit();

private:
	StopWatch m_timer;
	GLFWwindow* m_window;
	GLMouse mouse;
	Keyboard keyboard;
	Sound snd;
	Graphics gfx;
};