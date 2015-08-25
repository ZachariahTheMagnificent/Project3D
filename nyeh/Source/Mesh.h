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
	
	BoundingBox<float> GetBoundingBox() const;
};