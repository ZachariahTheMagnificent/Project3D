#ifndef SCENE_H
#define SCENE_H

#include "Keyboard.h"
#include "GLMouse.h"
#include "Sound.h"
#include "Graphics.h"
#include "Scene.h"
#include "timer.h"

class Scene
{
protected:
	Keyboard& keyboard;
	GLMouse& mouse;
	Graphics& gfx;
	Sound& snd;
	bool gameQuit;
public:
	Scene(Keyboard& keyboard, GLMouse& mouse, Sound& snd, Graphics& gfx)
		:
	keyboard(keyboard),
	mouse(mouse),
	gfx(gfx),
	gameQuit(false),
	snd(snd)
	{
		Math::InitRNG();
	}
	~Scene() {}

	virtual void Init() = 0;
	virtual void SendInfoToGFXCard() = 0;
	virtual bool Update(const double& dt) = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;
};

#endif