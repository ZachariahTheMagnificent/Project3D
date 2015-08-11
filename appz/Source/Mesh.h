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
#include "Polygon.h"
#include "BoundingBox.h"

/******************************************************************************/
/*!
Class Mesh:
\brief
To store VBO (vertex & color buffer) and polygons and generate voxels from them
*/
/******************************************************************************/

class Mesh
{
public:
	Mesh(const unsigned& nPolies = 0);
	~Mesh();
	
	void setPolySize(const unsigned& nPolies);

	Polygonn* GetPolyBuffer();
	const unsigned& GetNPolies() const;
	BoundingBox<float> GetBoundingBox() const;

private:
	Polygonn* polygons;
	unsigned nPolies;
};