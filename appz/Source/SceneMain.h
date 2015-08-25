/****************************************************************************/
/*!
\file SceneMain.h
\author Tan Jie Rong
\par email: soupsf@hotmail.com
\brief
Class SceneMain that updates and init, main scene to be rendered
*/
/****************************************************************************/
#pragma once

#include "Scene.h"
#include "Camera.h"
#include "MatrixStack.h"
#include "GlobalList.h"
#include "UI.h"
#include "CollisionSystem.h"
#include "FirstPersonMouse.h"
#include "Keyboard.h"
/****************************************************************************/
/*!
Class SceneMain:
\brief Defines SceneMain and it's method
*/
/****************************************************************************/
class SceneMain : public Scene
{
public:
	SceneMain(Keyboard* keyboard, FirstPersonMouse* mouse, Sound& snd, Graphics& gfx);
	~SceneMain();
	
	virtual void Init();
	virtual void SendInfoToGFXCard();
	virtual bool Update(const double& deltaTime);
	virtual void Render();
	virtual void Exit();
private:
	//globals
	GlobalList globals;
	Color* screenBuffer;

	//input
	Keyboard* keyboard;
	FirstPersonMouse* mouse;

	//physics
	AABBTree world;
	CollisionSystem collisionSystem;

	//rendering
	int screenX;
	int screenY;
	float fFov;
	float fNearPlane;
	float fFarPlane;
	Light light[1];
	Camera camera;
	UI ui;
	UI* currentUI;

	//functions
	void InnitTextures();
	void InnitLight();
	void InnitGeometry();
	void InnitDraws();
	void InnitForces();
	void InnitCollisions();
	void InnitLogic();
	void InnitSounds();
	void InnitMaterials();
	void InnitUI();
	void UpdateUserInput(const double& deltaTime);
	void UpdateLogic(const double& deltaTime);
	void UpdateView(const double& deltaTime);
	void UpdateLight(const double& deltaTime);
	void UpdateDraws(const double& deltaTime);
};
