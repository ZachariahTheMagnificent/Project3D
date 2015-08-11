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
#include <string>
#include <map>
/****************************************************************************/
/*!
Class GlobalList:
\brief
A list of all our assets
*/
/****************************************************************************/
typedef std::map<std::wstring, CollisionBody*> BodyMap;
typedef std::map<std::wstring, DrawOrder*> DrawMap;
typedef std::map<std::wstring, Mesh*> MeshMap;
typedef std::map<std::wstring, Material*> MaterialMap;
typedef std::map<std::wstring, Texture*> TextureMap;
typedef std::map<std::wstring, Camera*> CameraMap;
typedef std::map<std::wstring, Light*> LightMap;

class GlobalList
{
public:
	GlobalList();
	~GlobalList();

	Mesh* GetMesh(const std::wstring& meshName);
	DrawOrder* GetDraw(const std::wstring& drawName);
	Material* GetMaterial(const std::wstring& materialName);
	CollisionBody* GetCollisionBody(const std::wstring& collisionBodyName);
	Texture* GetTexture(const std::wstring& textureName);
	
	CollisionBody* GetBodies();
	DrawOrder* GetDraws();
	Mesh* GetMeshes();
	Material* GetMaterials();
	Texture* GetTextures();
	
	CollisionBody* GetLastBody();
	DrawOrder* GetLastDraw();
	Mesh* GetLastMesh();
	Material* GetLastMaterial();
	Texture* GetLastTexture();

private:
	MeshMap meshList;
	DrawMap drawList;
	MaterialMap materialList;
	BodyMap collisionBodiesList;
	TextureMap textureList;

	CollisionBody* bodies;
	DrawOrder* draws;
	Mesh* meshes;
	Material* materials;
	Texture* textures;

	CollisionBody* lastBody;
	DrawOrder* lastDraw;
	Mesh* lastMesh;
	Material* lastMaterial;
	Texture* lastTexture;

	unsigned bodyCapacity;
	unsigned drawCapacity;
	unsigned meshCapacity;
	unsigned materialCapacity;
	unsigned textureCapacity;
};