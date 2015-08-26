#pragma once
/****************************************************************************/
/*!
\file Mesh.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class used to store VBO (vertex & color buffer) and polygons and generate voxels from them
*/
/****************************************************************************/
#include "MyContainer.h"
#include "Polygon.h"
#include "BoundingBox.h"
#include "Mtx44.h"
#include "Material.h"

typedef BoundingBox<float> MeshBox;
/******************************************************************************/
/*!
Class Mesh:
\brief
To store VBO (vertex & color buffer) and polygons and generate voxels from them
*/
/******************************************************************************/

class Mesh : public MyContainer<Polygonn>
{
public:
	Mesh(const unsigned& nPolies = 0);
	virtual ~Mesh();
	
	virtual void Render(const Mtx44& projection, const Mtx44& view, const Mtx44& transform, const Material* material, const bool& lightingEnabled) const = 0;
	virtual void Render(const Mtx44& projection, const Mtx44& view, const Mtx44& transform, const Material* material, const bool& lightingEnabled, const unsigned& offset, const unsigned& count) const = 0;

	virtual MeshBox GetBoundingBox() const;
};