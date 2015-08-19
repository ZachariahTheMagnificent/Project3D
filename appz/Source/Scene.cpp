#include "Scene.h"

Scene::Scene(Sound& snd, Graphics& gfx)
	:
gfx(gfx),
snd(snd),
gameQuit(false)
{
	Math::InitRNG();
}

Scene::~Scene()
{
}