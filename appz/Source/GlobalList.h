#pragma once
/****************************************************************************/
/*!
\file GlobalList.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A list of all our assets
*/
/****************************************************************************/
#include "CollisionBody.h"
#include "Camera.h"
#include "Light.h"
#include "GLMesh.h"
#include "GLFont.h"
#include "GLTexture.h"
#include <string>
#include <map>
/****************************************************************************/
/*!
Class GlobalList:
\brief
A list of all our assets with names attached to each individual asset for ease of access and debugging during runtime
*/
/****************************************************************************/
typedef std::map<std::wstring, CollisionBody*> BodyMap;
typedef std::map<std::wstring, DrawOrder*> DrawMap;
typedef std::map<std::wstring, GLMesh*> MeshMap;
typedef std::map<std::wstring, Material*> MaterialMap;
typedef std::map<std::wstring, GLTexture*> TextureMap;
typedef std::map<std::wstring, Camera*> CameraMap;
typedef std::map<std::wstring, Light*> LightMap;

class GlobalList
{
public:
	GlobalList(Graphics* gfx);
	~GlobalList();

	GLMesh* GetMesh(const std::wstring& meshName);
	DrawOrder* GetDraw(const std::wstring& drawName);
	Material* GetMaterial(const std::wstring& materialName);
	CollisionBody* GetCollisionBody(const std::wstring& collisionBodyName);
	GLTexture* GetTexture(const std::wstring& textureName);
	
	CollisionBody* GetBodies();
	DrawOrder* GetDraws();
	GLMesh* GetMeshes();
	Material* GetMaterials();
	GLTexture* GetTextures();
	
	CollisionBody* GetLastBody();
	DrawOrder* GetLastDraw();
	GLMesh* GetLastMesh();
	Material* GetLastMaterial();
	GLTexture* GetLastTexture();

private:
	MeshMap meshList;
	DrawMap drawList;
	MaterialMap materialList;
	BodyMap collisionBodiesList;
	TextureMap textureList;

	CollisionBody* bodies;
	DrawOrder* draws;
	GLMesh* meshes;
	Material* materials;
	GLTexture* textures;

	CollisionBody* lastBody;
	DrawOrder* lastDraw;
	GLMesh* lastMesh;
	Material* lastMaterial;
	GLTexture* lastTexture;

	unsigned bodyCapacity;
	unsigned drawCapacity;
	unsigned meshCapacity;
	unsigned materialCapacity;
	unsigned textureCapacity;

	Graphics* gfx;
};