#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "timer.h"
#include "Sound.h"
#include "Graphics.h"
#include "WindowsKeyboard.h"
#include "GLMouse.h"
#include "SceneMain.h"

class Application
{
public:
	Application();
	~Application();
	void Init();
	void Run();
	void Exit();

private:
	SceneMain mainScene;
	StopWatch m_timer;
	GLFWwindow* m_window;
	GLMouse mouse;
	WindowsKeyboard keyboard;
	Sound snd;
	Graphics gfx;
};