#pragma once

#include "Sound.h"
#include "Graphics.h"
#include "timer.h"

class Scene
{
public:
	Scene(Sound& snd, Graphics& gfx);
	~Scene();

	virtual void Init() = 0;
	virtual void SendInfoToGFXCard() = 0;
	virtual bool Update(const double& deltaTime) = 0;
	virtual void Render() = 0;
	virtual void Exit() = 0;

protected:
	Graphics& gfx;
	Sound& snd;
	bool gameQuit;
};