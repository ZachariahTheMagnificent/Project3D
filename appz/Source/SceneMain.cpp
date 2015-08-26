/****************************************************************************/
/*!
\file SceneMain.cpp
\author Tan Jie Rong
\par email: soupsf@hotmail.com
\brief
Scene that updates and init, main scene to be rendered
*/
/****************************************************************************/
#include "SceneMain.h"
#include "MeshBuilder.h"
#include "LoadTGA.h"
/****************************************************************************/
/*!
\brief
constructor to get mouse keyboard sound and graphics obj
\param Keyboard& keyboard 
object from keyboard class
\param GLMouse& mouse
object from GLmosuse class
\param Sound& snd
object from Sound class
\param Graphics& gfx
object from Graphics class
*/
/****************************************************************************/
SceneMain::SceneMain(Keyboard* keyboard, FirstPersonMouse* mouse, Sound& snd, Graphics& gfx)
	:
Scene(snd, gfx),
keyboard(keyboard),
mouse(mouse),
collisionSystem(),
screenBuffer(NULL),
globals(&gfx)
{
}
/****************************************************************************/
/*!
\brief
default destructor
*/
/****************************************************************************/
SceneMain::~SceneMain()
{
}
/****************************************************************************/
/*!
\brief
Initialize all variables used and also to pass in DrawOrders for other classes
*/
/****************************************************************************/
void SceneMain::Init()
{
	InnitLight();
	InnitTextures();
	InnitMaterials();
	InnitSounds();
	InnitGeometry();
	InnitDraws();
	InnitCollisions();
	InnitForces();
	InnitLogic();

	gfx.GetWindowSize(&screenX, &screenY);
	screenBuffer = new Color[screenX*screenY];

	camera.Init(Vector3(0, 7, 5), Vector3(1, 0, 0), Vector3(0, 1, 0));
	fFov = 45.f;
	fNearPlane = 0.1f;
	fFarPlane = 142000.f;
	gfx.SetProjectionTo(fFov, screenX / (float)screenY, fNearPlane, fFarPlane);
	gfx.InitText(globals.GetDraw(L"text"));
}

void SceneMain::SendInfoToGFXCard()
{
	gfx.SendTextureInfo(globals.GetTextures(), globals.GetLastTexture());

	gfx.SendMeshInfo(globals.GetMeshes(), globals.GetLastMesh());
}

/****************************************************************************/
/*!
\brief
Initializes Sound
*/
/****************************************************************************/
void SceneMain::InnitSounds()
{
	snd.loadWave("halot","sound//halot.wav");
	snd.loadWave("hitsound","sound//jump-small.wav");
}
/****************************************************************************/
/*!
\brief
Initializes logic like FPS and dt
*/
/****************************************************************************/
void SceneMain::InnitLogic()
{
}
/****************************************************************************/
/*!
\brief
Initializes texture
*/
/****************************************************************************/
void SceneMain::InnitTextures()
{
	Texture* texture;

	texture = globals.GetTexture(L"skybox");
	TGALoader::LoadTGA(L"Image//skybox.tga", texture);

	texture = globals.GetTexture(L"ground");
	TGALoader::LoadTGA(L"Image//ground.tga", texture);

	texture = globals.GetTexture(L"target");
	TGALoader::LoadTGA(L"Image//white.tga", texture);

	texture = globals.GetTexture(L"didact");
	TGALoader::LoadTGA(L"Image//didact.tga", texture);

	texture = globals.GetTexture(L"door");
	TGALoader::LoadTGA(L"Image//door.tga", texture);

	texture = globals.GetTexture(L"electronic_circuit");
	TGALoader::LoadTGA(L"Image//electronic_circuit.tga", texture);

	texture = globals.GetTexture(L"football_field");
	TGALoader::LoadTGA(L"Image//football_field.tga", texture);

	texture = globals.GetTexture(L"kitten_bri");
	TGALoader::LoadTGA(L"Image//kitten_bri.tga", texture);

	texture = globals.GetTexture(L"large_forerunner_floor_plate");
	TGALoader::LoadTGA(L"Image//large_forerunner_floor_plate.tga", texture);

	texture = globals.GetTexture(L"metalplatefloorfull");
	TGALoader::LoadTGA(L"Image//metalplatefloorfull.tga", texture);

	texture = globals.GetTexture(L"metal_tile");
	TGALoader::LoadTGA(L"Image//metal_tile.tga", texture);

	texture = globals.GetTexture(L"plate_metal");
	TGALoader::LoadTGA(L"Image//plate_metal.tga", texture);

	texture = globals.GetTexture(L"ring");
	TGALoader::LoadTGA(L"Image//ring.tga", texture);

	texture = globals.GetTexture(L"text");
	TGALoader::LoadTGA(L"Image//ArialBlack.tga", texture);
}
/****************************************************************************/
/*!
\brief
Initializes material, combining texture and lighting.
*/
/****************************************************************************/
void SceneMain::InnitMaterials()
{
	float AmbientLight = 0.5;
	Material* mat;
	mat = globals.GetMaterial(L"skybox");
	mat->SetTo(Color(AmbientLight, AmbientLight, AmbientLight), Color(1, 1, 1), Color(1, 1, 1), 20, globals.GetTexture(L"skybox"));
	
	mat = globals.GetMaterial(L"voxel");
	mat->SetTo(Color(AmbientLight,  AmbientLight,  AmbientLight), Color(1,  1,  1), Color(1,  1,  1),  20,  NULL);

	mat = globals.GetMaterial(L"ground");
	mat->SetTo(Color(AmbientLight, AmbientLight, AmbientLight), Color(1, 1, 1), Color(1, 1, 1), 20,  globals.GetTexture(L"ground"));

	mat = globals.GetMaterial(L"target");
	mat->SetTo(Color(AmbientLight, AmbientLight, AmbientLight), Color(1, 1, 1), Color(1, 1, 1), 20,  globals.GetTexture(L"target"));

	mat = globals.GetMaterial(L"didact");
	mat->SetTo(Color(1, 1, 1),  Color(1, 1, 1), Color(1, 1, 1), 200,  globals.GetTexture(L"didact"));

	mat = globals.GetMaterial(L"stone");
	mat->SetTo(Color(1, 1, 1), Color(1, 1, 1), Color(1, 1, 1), 20,  globals.GetTexture(L"door"));

	mat = globals.GetMaterial(L"corrupted");
	mat->SetTo(Color(1, 1, 1), Color(1, 1, 1), Color(1, 1, 1), 20,  globals.GetTexture(L"electronic_circuit"));

	mat = globals.GetMaterial(L"football field");
	mat->SetTo(Color(1, 1, 1), Color(1, 1, 1), Color(1, 1, 1), 20,  globals.GetTexture(L"football_field"));

	mat = globals.GetMaterial(L"kittenbri");
	mat->SetTo(Color(1, 1, 1), Color(1, 1, 1), Color(1, 1, 1), 20,  globals.GetTexture(L"kitten_bri"));

	mat = globals.GetMaterial(L"forerunner plate");
	mat->SetTo(Color(1, 1, 1), Color(1, 1, 1), Color(1, 1, 1), 20,  globals.GetTexture(L"large_forerunner_floor_plate"));

	mat = globals.GetMaterial(L"metal floor");
	mat->SetTo(Color(1, 1, 1), Color(1, 1, 1), Color(1, 1, 1), 20,  globals.GetTexture(L"metalplatefloorfull"));

	mat = globals.GetMaterial(L"metal tile");
	mat->SetTo(Color(1, 1, 1), Color(1, 1, 1), Color(1, 1, 1), 20,  globals.GetTexture(L"metal_tile"));

	mat = globals.GetMaterial(L"plate metal");
	mat->SetTo(Color(1, 1, 1), Color(1, 1, 1), Color(1, 1, 1), 20,  globals.GetTexture(L"plate_metal"));

	mat = globals.GetMaterial(L"rock");
	mat->SetTo(Color(1, 1, 1), Color(1, 1, 1), Color(1, 1, 1), 20,  globals.GetTexture(L"ring"));
	
	mat = globals.GetMaterial(L"text");
	mat->SetTo(Color(1,1,1), Color(1,1,1), Color(1,1,1), 20, globals.GetTexture(L"text"));
}
/****************************************************************************/
/*!
\brief
Initializes light used
*/
/****************************************************************************/
void SceneMain::InnitLight()
{
	light[0].type = Light::LIGHT_DIRECTIONAL;
	light[0].position.Set(20, 20, 20);
	light[0].color.Set(1, 1, 1);
	light[0].power = 0.25;
	light[0].kC = 1.f;
	light[0].kL = 0.01f;
	light[0].kQ = 0.001f;
	light[0].cosCutoff = cos(Math::DegreeToRadian(180));
	light[0].cosInner = cos(Math::DegreeToRadian(30));
	light[0].exponent = 1.f;
	light[0].spotDirection.Set(0.f, 1.f, 1.f);

	gfx.AddLight(&light[0]);
}
/****************************************************************************/
/*!
\brief
Initializes geometry and obj
*/
/****************************************************************************/
void SceneMain::InnitGeometry()
{
	Mesh* mesh;

	mesh = globals.GetMesh(L"skybox");
	MeshBuilder::GenerateOBJ(mesh, L"OBJ//skybox.obj");

	mesh = globals.GetMesh(L"plane");
	MeshBuilder::GenerateQuad(mesh, Color(), 1, 1);

	mesh = globals.GetMesh(L"cube");
	MeshBuilder::GenerateOBJ(mesh, L"OBJ//cubey.obj");

	mesh = globals.GetMesh(L"sphere");
	MeshBuilder::GenerateOBJ(mesh, L"OBJ//sphere.obj");

	mesh = globals.GetMesh(L"nirvana");
	MeshBuilder::GenerateOBJ(mesh, L"OBJ//nirvana.obj");

	mesh = globals.GetMesh(L"nirvana collision");
	MeshBuilder::GenerateOBJ(mesh, L"OBJ//nirvana collision.obj");

	mesh = globals.GetMesh(L"football field");
	MeshBuilder::GenerateOBJ(mesh, L"OBJ//football field.obj");

	mesh = globals.GetMesh(L"sentinel");
	MeshBuilder::GenerateOBJ(mesh, L"OBJ//sentinel.obj");

	mesh = globals.GetMesh(L"lift");
	MeshBuilder::GenerateOBJ(mesh, L"OBJ//lift.obj");

	mesh = globals.GetMesh(L"didact");
	MeshBuilder::GenerateOBJ(mesh, L"OBJ//didact.obj");

	mesh = globals.GetMesh(L"door");
	MeshBuilder::GenerateOBJ(mesh, L"OBJ//door.obj");

	mesh = globals.GetMesh(L"ring");
	MeshBuilder::GenerateOBJ(mesh, L"OBJ//ring.obj");

	mesh = globals.GetMesh(L"stadium");
	MeshBuilder::GenerateOBJ(mesh, L"OBJ//stadium.obj");
	
	mesh = globals.GetMesh(L"text");
	MeshBuilder::GenerateText(mesh, 16, 16);
}
/****************************************************************************/
/*!
\brief
function to draw/load out every obj or images that will appear in scene
*/
/****************************************************************************/
void SceneMain::InnitDraws()
{
	DrawOrder* draw;

	//main will be the main draw order that all other draw orders are children of
	globals.GetDraw(L"main");

	//Draw SkyBox
	draw = globals.GetDraw(L"skybox");
	draw->SetTo(globals.GetMesh(L"skybox"), globals.GetMaterial(L"skybox"), globals.GetDraw(L"main"), false);
	draw->transform.translate.Set(0,0,0);
	draw->transform.scale.Set(10000,10000,10000);
	
	//Draw voxel
	draw = globals.GetDraw(L"voxel");
	draw->SetTo(globals.GetMesh(L"cube"), globals.GetMaterial(L"voxel"), NULL, false);

	//Draw player1
	draw = globals.GetDraw(L"player1");
	draw->SetTo(globals.GetMesh(L"sentinel"), globals.GetMaterial(L"forerunner plate"), globals.GetDraw(L"main"), false);
	//draw->transform.translate.Set(21.7, 5, 68.3);
	draw->transform.translate.Set(-217, -631, 0);
	
	//Draw player2
	draw = globals.GetDraw(L"player2");
	draw->SetTo(globals.GetMesh(L"sentinel"), globals.GetMaterial(L"metal floor"), globals.GetDraw(L"main"), false);
	draw->transform.translate.Set(-217, -631, -20);

	//Draw ball
	draw = globals.GetDraw(L"sphere");
	draw->SetTo(globals.GetMesh(L"sphere"), globals.GetMaterial(L"rock"), globals.GetDraw(L"main"), false);
	draw->transform.translate.Set(-217, -631, 20);

	//draw one of the lifts
	draw = globals.GetDraw(L"left lift");
	draw->SetTo(globals.GetMesh(L"lift"), globals.GetMaterial(L"forerunner plate"), globals.GetDraw(L"main"), true);
	draw->transform.translate.Set(0, 100, 0);
	//draw->SetTerminalVelocityTo(Vector3(60,60,60));
	//draw->mass = 100;
	
	//draw the level
	draw = globals.GetDraw(L"nirvana");
	draw->SetTo(globals.GetMesh(L"nirvana"), globals.GetMaterial(L"metal floor"), globals.GetDraw(L"main"), true);
	//draw->SetTo(globals.GetMesh(L"stadium"), globals.GetMaterial(L"metal floor"), globals.GetDraw(L"main"), true);
	//draw->transform.translate.Set(0,0,0);
	//draw->kineticFriction = 0.25;
	
	//draw the football field
	draw = globals.GetDraw(L"football field");
	draw->SetTo(globals.GetMesh(L"football field"), globals.GetMaterial(L"football field"), globals.GetDraw(L"nirvana"), true);
	
	//draw the ring at the centre
	draw = globals.GetDraw(L"ring");
	draw->SetTo(globals.GetMesh(L"ring"), globals.GetMaterial(L"rock"), globals.GetDraw(L"main"), false);
	draw->transform.translate.Set(-1000,0,0);
	//draw->SetTerminalVelocityTo(Vector3(60,60,60));
	
	//draw the corrupted sentinel
	draw = globals.GetDraw(L"currupted sentinel");
	draw->SetTo(globals.GetMesh(L"sentinel"), globals.GetMaterial(L"corrupted"), globals.GetDraw(L"main"), true);
	draw->transform.translate.Set(-23.3f, 3.7f, 69.9f);
	
	//draw the rock sentinel
	draw = globals.GetDraw(L"rock sentinel");
	draw->SetTo(globals.GetMesh(L"sentinel"), globals.GetMaterial(L"rock"), globals.GetDraw(L"main"), true);
	draw->transform.translate.Set(-1000,0,0);
	
	//draw the stone sentinel
	draw = globals.GetDraw(L"stone sentinel");
	draw->SetTo(globals.GetMesh(L"sentinel"), globals.GetMaterial(L"stone"), globals.GetDraw(L"main"), true);
	draw->transform.translate.Set(-1000,0,0);
	
	//draw the wise sentinel
	draw = globals.GetDraw(L"wise sentinel");
	draw->SetTo(globals.GetMesh(L"sentinel"), globals.GetMaterial(L"plate metal"), globals.GetDraw(L"main"), true);
	draw->transform.translate.Set(-1000,0,0);
	
	//draw the sneaky sentinel
	draw = globals.GetDraw(L"sneaky sentinel");
	draw->SetTo(globals.GetMesh(L"sentinel"), globals.GetMaterial(L"forerunner plate"), globals.GetDraw(L"main"), true);
	draw->transform.translate.Set(-1000,0,0);
	
	//draw the pure sentinel
	draw = globals.GetDraw(L"pure sentinel");
	draw->SetTo(globals.GetMesh(L"sentinel"), globals.GetMaterial(L"plate metal"), globals.GetDraw(L"main"), true);
	draw->transform.translate.Set(-23.2f, 4.25f, -69.8f);

	//draw the master sentinel
	draw = globals.GetDraw(L"master sentinel");
	draw->SetTo(globals.GetMesh(L"sentinel"), globals.GetMaterial(L"forerunner plate"), NULL, true);
	draw->transform.translate.Set(1, 1, 1);

	//draw the meshText
	draw = globals.GetDraw(L"text");
	draw->SetTo(globals.GetMesh(L"text"), globals.GetMaterial(L"text"), NULL, false);
}

void SceneMain::InnitUI()
{
}

/****************************************************************************/
/*!
\brief
initialising collisions with obj
*/
/****************************************************************************/
void SceneMain::InnitCollisions()
{
	CollisionBody* body;

	body = globals.GetCollisionBody(L"player");
	body->draw = globals.GetDraw(L"player1");
	body->mesh = globals.GetMesh(L"sphere");
	body->mass = 1;
	body->SetTerminalVelocityTo(100);
	body->SetDecelerationTo(10);
	body->soundSys = &snd;
	
	body = globals.GetCollisionBody(L"player2");
	body->draw = globals.GetDraw(L"player2");
	body->mesh = globals.GetMesh(L"sphere");
	body->mass = 1;
	body->SetTerminalVelocityTo(100);
	body->SetDecelerationTo(10);
	body->soundSys = &snd;
	
	body = globals.GetCollisionBody(L"sphere");
	body->draw = globals.GetDraw(L"sphere");
	body->mesh = globals.GetMesh(L"sphere");
	body->mass = 1;
	body->SetTerminalVelocityTo(100);
	body->SetDecelerationTo(10);

	body = globals.GetCollisionBody(L"nirvana");
	body->draw = globals.GetDraw(L"nirvana");
	body->mesh = globals.GetMesh(L"nirvana");

	body = globals.GetCollisionBody(L"football field");
	body->draw = globals.GetDraw(L"football field");
	body->mesh = globals.GetMesh(L"football field");

	body = globals.GetCollisionBody(L"ring");
	body->draw = globals.GetDraw(L"ring");
	body->mesh = globals.GetMesh(L"ring");
	body->rotationVelocity.x = 3;
	
	body = globals.GetCollisionBody(L"pure sentinel");
	body->draw = globals.GetDraw(L"pure sentinel");
	body->mesh = globals.GetMesh(L"sentinel");
	
	body = globals.GetCollisionBody(L"currupted sentinel");
	body->draw = globals.GetDraw(L"currupted sentinel");
	body->mesh = globals.GetMesh(L"sentinel");
	
	unsigned numOfPolys = 0;

	//Update the velocity of all draws before doing collision
	CollisionBody*const begin = globals.GetBodies();
	CollisionBody*const end = globals.GetLastBody();
	for(CollisionBody* body = begin; body != end; ++body)
	{
		Mesh* mesh = body->mesh;
		if(mesh)
		{
			const Polygonn* polies = mesh->GetBegin();
			const unsigned size = mesh->GetSize();
			numOfPolys += size;

			body->tree.IncreaseCapacityTo(size);

			Mtx44 mtx1 = body->GetMatrix();

			AABBTreeNode* node = body->tree.GetBegin();
			AABBTreeNode* nodeEnd = body->tree.GetEnd();
			
			AABBBox box(Range<float>(FLT_MAX, -FLT_MAX), Range<float>(FLT_MAX, -FLT_MAX), Range<float>(FLT_MAX, -FLT_MAX));
			const Polygonn* begin = polies;
			const Polygonn* end = begin + size;
			for(Polygonn const* it = begin; it != end && node != nodeEnd; ++it, ++node)
			{
				node->data = *it;
				node->data.MoveBy(mtx1);
				node->box = node->data.GetBoundingBox();

				box.ResizeToFit(node->box);
			}
			body->tree.Sort(box, end - begin);
		}
	}
	world.IncreaseCapacityTo(numOfPolys);
}

/****************************************************************************/
/*!
\brief
initializing forces, acceleration.
*/
/****************************************************************************/
void SceneMain::InnitForces()
{
	Vector3 accelerationDueToGravity(0, -9.8f, 0);

	CollisionBody*const begin = globals.GetBodies();
	CollisionBody*const end = globals.GetLastBody();
	for(CollisionBody* body = begin; body != end; ++body)
	{
		body->AddForce(accelerationDueToGravity * body->mass);
	}
}
/****************************************************************************/
/*!
\brief
updating of scene 
\param dt - deltatime
used to take in deltatime which allow movements and animations
\return
is update true or false
*/
/****************************************************************************/
bool SceneMain::Update(const double& deltaTime)
{
	if(keyboard->IsKeyPressed(VK_ESCAPE))
	{
		return true;
	}

	//rendering mouse
	Vector2 mousePosition = mouse->GetPosition();
	Mtx44 cursorPosition;
	cursorPosition.SetToTranslation(Vector3(mousePosition.x, mousePosition.y, 0));

	gfx.GetWindowSize(&screenX, &screenY);
	UpdateUserInput(deltaTime);
	UpdateDraws(deltaTime);
	UpdateView(deltaTime);
	UpdateLight(deltaTime);
	UpdateLogic(deltaTime);

	return false;
}
/****************************************************************************/
/*!
\brief
updating Logic for lifts, doors and main menus
*/
/****************************************************************************/
void SceneMain::UpdateLogic(const double& deltaTime)
{
}
/****************************************************************************/
/*!
\brief
updating view in frog and player perspective, camera lock on.
*/
/****************************************************************************/
void SceneMain::UpdateView(const double& deltaTime)
{
	DrawOrder* skybox = globals.GetDraw(L"skybox");

	CollisionBody* currentPlayer = globals.GetCollisionBody(L"player");
	//the skybox is moved according to the camera position
	skybox->transform.translate = Vector3(0,0,0) + camera.ReturnPosition();
	Vector3 displacement(0, 0, -1);
	//camera.SetRotate(currentPlayer->draw->transform.rotate);
	Mtx44 rotation;
	rotation = camera.GetRotationMatrix(0,0,1);
	displacement = rotation * displacement;
	camera.Translate(currentPlayer->draw->transform.translate - camera.ReturnPosition() + displacement);

	gfx.SetProjectionTo(fFov, screenX / (float)screenY, fNearPlane, fFarPlane);
	gfx.SetViewAt(camera);
}
/****************************************************************************/
/*!
\brief
updating lights
*/
/****************************************************************************/
void SceneMain::UpdateLight(const double& deltaTime)
{
	gfx.UpdateLights();
}
/****************************************************************************/
/*!
\brief
updating draws
*/
/****************************************************************************/
void SceneMain::UpdateDraws(const double& deltaTime)
{
	CollisionBody* currentPlayer = globals.GetCollisionBody(L"player");
	Rotation rotate = camera.GetRotation() - currentPlayer->draw->transform.rotate;
	currentPlayer->rotationVelocity.Set(rotate.yaw, 0, 0);

	//Update the velocity of all draws before doing collision
	CollisionBody*const begin = globals.GetBodies();
	CollisionBody*const end = globals.GetLastBody();
	for(CollisionBody* body = begin; body != end; ++body)
	{
		body->UpdateVelocity(deltaTime);

		if(body->velocity.IsZero())
		{
			continue;
		}

		Mesh* mesh = body->mesh;

		if(mesh)
		{
			const Polygonn* polies = mesh->GetBegin();
			const unsigned size = mesh->GetSize();
			body->tree.IncreaseCapacityTo(size);

			body->TempUpdateTo(deltaTime);
			Mtx44 mtx1 = body->GetMatrix();
			body->TempUpdateTo(-deltaTime);

			AABBTreeNode* node = body->tree.GetBegin();
			AABBTreeNode* nodeEnd = body->tree.GetEnd();

			AABBBox box(Range<float>(FLT_MAX, -FLT_MAX), Range<float>(FLT_MAX, -FLT_MAX), Range<float>(FLT_MAX, -FLT_MAX));
			const Polygonn* begin = polies;
			const Polygonn* end = begin + size;
			for(Polygonn const* it = begin; it != end && node != nodeEnd; ++it, ++node)
			{
				node->data = *it;
				node->data.MoveBy(mtx1);
				node->box = node->data.GetBoundingBox();

				box.ResizeToFit(node->box);
			}
			body->tree.Sort(box, end - begin);
		}
	}

	collisionSystem.UpdateTo(deltaTime, begin, end);

	//update the draws
	for(CollisionBody* body = begin; body != end; ++body)
	{
		body->UpdateTo(deltaTime);
	}
}
/****************************************************************************/
/*!
\brief
rendering of text, sounds and menu options
*/
/****************************************************************************/
void SceneMain::Render()
{
	gfx.BeginDrawing();

	gfx.RenderDraw(globals.GetDraw(L"main"));

	//gfx.RenderUI(currentUI);

	//gfx.RenderTextOnScreen(buffer1,Color(0,1,0),20,1,1);
	//gfx.RenderTextOnScreen(text.GetText(),Color(0,1,0),20,1,40, ORIENTATION_TOP);

	MS matrixStack;
	matrixStack.Translate(110,67,100);
	matrixStack.Scale(30,30,30);

	matrixStack.MultMatrix(camera.GetRotationMatrix(1,0,1));
	gfx.RenderMeshOnScreen(*globals.GetDraw(L"master sentinel"), matrixStack.Top());

	gfx.EndDrawing();
}
/****************************************************************************/
/*!
\brief
empty exit
*/
/****************************************************************************/
void SceneMain::Exit()
{
	if(screenBuffer)
	{
		delete [] screenBuffer;
	}
	snd.stopSound();
}
/****************************************************************************/
/*!
\brief
All user inputs
*/
/****************************************************************************/
void SceneMain::UpdateUserInput(const double& deltaTime)
{
	if(keyboard->IsKeyPressed('X'))
	{
		mouse->ToggleLock();
	}

	Vector2 mouseVector = mouse->GetDisplacementFromCentre();
	const double CAMERA_SPEED = 2.5;
	double movingSpeed = 30;

	camera.Rotate(-mouseVector.x * deltaTime, mouseVector.y * deltaTime, 0);

	if (keyboard->IsKeyHold(VK_SHIFT))
	{
		movingSpeed *= 3 ;
	}
	Vector3 right = camera.GetTarget().Cross(Vector3(0,1,0)), target = camera.GetTarget();
	target.y = 0;
	Vector3 direction;
	if (keyboard->IsKeyHold('W'))
	{
		//globals.GetDraw(L"player").transform.translate += target * dDeltatime * movingSpeed;
		direction += target;
	}
	if (keyboard->IsKeyHold('A'))
	{
		//globals.GetDraw(L"player").transform.translate += -right * dDeltatime * movingSpeed;
		direction += -right;
	}
	if (keyboard->IsKeyHold('S'))
	{
		//globals.GetDraw(L"player").transform.translate += -target * dDeltatime * movingSpeed;
		direction += -target;
	}
	if (keyboard->IsKeyHold('D'))
	{
		//globals.GetDraw(L"player").transform.translate += right * dDeltatime * movingSpeed;
		direction += right;
	}
	if (keyboard->IsKeyHold(' '))
	{
		//globals.GetDraw(L"player").transform.translate += right * dDeltatime * movingSpeed;
		direction.y = 1;
	}
	const float playerspeed = 20;
	if(!direction.IsZero())
	{
		direction.Normalize() *= playerspeed;
	}
	Force force;
	force.SetLifespanTo(0.001f);
	force.SetVector(direction);
	CollisionBody* currentPlayer = globals.GetCollisionBody(L"player");
	currentPlayer->AddForce(force);

	if(keyboard->IsKeyHold('Q'))
	{
		camera.Rotate(0, 5 * deltaTime * movingSpeed, 0);
	}
	if(keyboard->IsKeyHold('E'))
	{
		camera.Rotate(0, -5 * deltaTime * movingSpeed, 0);
	}

	if (keyboard->IsKeyHold(VK_UP))
	{
		camera.Move(10.0f * deltaTime * CAMERA_SPEED, 0.0f, 0.0f);
	}
	if (keyboard->IsKeyHold(VK_LEFT))
	{
		camera.Move(0.0f, 0.0f, -10.0f * deltaTime * CAMERA_SPEED);
	}
	if (keyboard->IsKeyHold(VK_DOWN))
	{
		camera.Move(-10.0f * deltaTime * CAMERA_SPEED, 0.0f, 0.0f);
	}
	if (keyboard->IsKeyHold(VK_RIGHT))
	{
		camera.Move(0.0f, 0.0f, 10.0f * deltaTime * CAMERA_SPEED);
	}
	if (keyboard->IsKeyHold(VK_SPACE))
	{
		camera.Move(0,10 * deltaTime * CAMERA_SPEED,0);
	}
	if (keyboard->IsKeyHold(VK_CONTROL))
	{
		camera.Move(0,-10 * deltaTime * CAMERA_SPEED,0);
	}
}