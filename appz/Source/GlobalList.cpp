#include "GlobalList.h"
/****************************************************************************/
/*!
\file GlobalList.cpp
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A list of all our assets
*/
/****************************************************************************/

/****************************************************************************/
/*!
\brief
Default constructor
*/
/****************************************************************************/
GlobalList::GlobalList()
	:
bodies(NULL),
draws(NULL),
meshes(NULL),
materials(NULL),
textures(NULL),
lastBody(NULL),
lastDraw(NULL),
lastMesh(NULL),
lastMaterial(NULL),
lastTexture(NULL),
bodyCapacity(100),
drawCapacity(100),
meshCapacity(100),
materialCapacity(100),
textureCapacity(100)
{
	bodies = new CollisionBody[bodyCapacity];
	lastBody = bodies;

	draws = new DrawOrder[drawCapacity];
	lastDraw = draws;

	meshes = new Mesh[meshCapacity];
	lastMesh = meshes;

	materials = new Material[materialCapacity];
	lastMaterial = materials;

	textures = new Texture[textureCapacity];
	lastTexture = textures;
}
/****************************************************************************/
/*!
\brief
Default destructor
*/
/****************************************************************************/
GlobalList::~GlobalList()
{
	if(bodies)
	{
		delete [] bodies;
		bodies = NULL;
	}
	if(draws)
	{
		delete [] draws;
		draws = NULL;
	}
	if(meshes)
	{
		delete [] meshes;
		meshes = NULL;
	}
	if(materials)
	{
		delete [] materials;
		materials = NULL;
	}
	if(textures)
	{
		delete [] textures;
		textures = NULL;
	}
}
/****************************************************************************/
/*!
\brief
Get a mesh from the list
\param meshName
		the name of the mesh
*/
/****************************************************************************/
Mesh* GlobalList::GetMesh(const std::wstring& meshName)
{
	MeshMap::iterator it = meshList.find(meshName);
	if(it != meshList.end())
	{
		return it->second;
	}
	else
	{
		if(lastMesh == meshes + meshCapacity)
		{
			throw;
		}
		meshList[meshName] = lastMesh;
		return lastMesh++;
	}
}
/****************************************************************************/
/*!
\brief
Get a DrawOrder from the list
\param drawName
		the name of the DrawOrder
*/
/****************************************************************************/
DrawOrder* GlobalList::GetDraw(const std::wstring& drawName)
{
	DrawMap::iterator it = drawList.find(drawName);
	if(it != drawList.end())
	{
		return it->second;
	}
	else
	{
		if(lastDraw == draws + drawCapacity)
		{
			throw;
		}
		drawList[drawName] = lastDraw;
		return lastDraw++;
	}
}
/****************************************************************************/
/*!
\brief
Get a material from the list
\param materialName
		the name of the material
*/
/****************************************************************************/
Material* GlobalList::GetMaterial(const std::wstring& materialName)
{
	MaterialMap::iterator it = materialList.find(materialName);
	if(it != materialList.end())
	{
		return it->second;
	}
	else
	{
		if(lastMaterial == materials + materialCapacity)
		{
			throw;
		}
		materialList[materialName] = lastMaterial;
		return lastMaterial++;
	}
}
/****************************************************************************/
/*!
\brief
Get a collision body from the list
\param Name
		the name of the collision body
*/
/****************************************************************************/
CollisionBody* GlobalList::GetCollisionBody(const std::wstring& collisionBodyName)
{
	BodyMap::iterator it = collisionBodiesList.find(collisionBodyName);
	if(it != collisionBodiesList.end())
	{
		return it->second;
	}
	else
	{
		if(lastBody == bodies + bodyCapacity)
		{
			throw;
		}
		collisionBodiesList[collisionBodyName] = lastBody;
		return lastBody++;
	}
}
/****************************************************************************/
/*!
\brief
Get a texture from the list
\param Name
		the name of the texture
*/
/****************************************************************************/
Texture* GlobalList::GetTexture(const std::wstring& textureName)
{
	TextureMap::iterator it = textureList.find(textureName);
	if(it != textureList.end())
	{
		return it->second;
	}
	else
	{
		if(lastTexture == textures + textureCapacity)
		{
			throw;
		}
		textureList[textureName] = lastTexture;
		return lastTexture++;
	}
}

CollisionBody* GlobalList::GetBodies()
{
	return bodies;
}

DrawOrder* GlobalList::GetDraws()
{
	return draws;
}

Mesh* GlobalList::GetMeshes()
{
	return meshes;
}

Material* GlobalList::GetMaterials()
{
	return materials;
}

Texture* GlobalList::GetTextures()
{
	return textures;
}
	
CollisionBody* GlobalList::GetLastBody()
{
	return lastBody;
}

DrawOrder* GlobalList::GetLastDraw()
{
	return lastDraw;
}

Mesh* GlobalList::GetLastMesh()
{
	return lastMesh;
}

Material* GlobalList::GetLastMaterial()
{
	return lastMaterial;
}

Texture* GlobalList::GetLastTexture()
{
	return lastTexture;
}