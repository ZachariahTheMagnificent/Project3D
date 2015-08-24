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
	~SceneMain(void);
	
	virtual void Init();
	virtual void SendInfoToGFXCard();
	virtual bool Update(const double& dt);
	virtual void Render();
	virtual void Exit();
private:
	GlobalList globals;
	Color* screenBuffer;

	//input
	Keyboard* keyboard;
	FirstPersonMouse* mouse;

	//physics
	AABBTree world;

	//rendering
	int screenX;
	int screenY;
	float fFov;
	float fNearPlane;
	float fFarPlane;
	Light light[1];
	Camera camera;

	//print fps
	double dDeltatime;
	double dCurrentFPS;
	CollisionSystem collisionSystem;

	//logic
	CollisionBody* currentPlayer;
	bool bDrawVoxels;
	bool lookWithMouse;

	//functions
	void DoUserInput();
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
	void UpdateLogic();
	void UpdateView();
	void UpdateLight();
	void UpdateDraws();
};
