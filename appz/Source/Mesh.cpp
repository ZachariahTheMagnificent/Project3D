#include "Mesh.h"
/****************************************************************************/
/*!
\file Mesh.cpp
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class used to store VBO (vertex & color buffer) and polygons and generate voxels from them
*/
/****************************************************************************/

/****************************************************************************/
/*!
\brief
default constructor
\param meshName
		the name of the mesh
\param Vertex_buffer
		the buffer containing all our vertices
*/
/****************************************************************************/
Mesh::Mesh(const unsigned& nPolies)
	:
polygons(NULL),
nPolies(nPolies)
{
	if(nPolies)
	{
		polygons = new Polygonn[nPolies];
	}
}

void Mesh::setPolySize(const unsigned& nPolies)
{
	if(this->nPolies == nPolies)
	{
		return;
	}

	this->nPolies = nPolies;

	if(nPolies)
	{
		delete [] polygons;
		polygons = NULL;
	}

	if(nPolies)
	{
		polygons = new Polygonn[nPolies];
	}
}

/****************************************************************************/
/*!
\brief
default destructor
*/
/****************************************************************************/
Mesh::~Mesh()
{
	if(polygons)
	{
		delete [] polygons;
		polygons = NULL;
	}
}
/****************************************************************************/
/*!
\brief
Returns the bounds of the mesh
\param rangeX
		the reference to the buffer storing the x-range
\param rangeY
		the reference to the buffer storing the y-range
\param rangeZ
		the reference to the buffer storing the z-range
*/
/****************************************************************************/
BoundingBox<float> Mesh::GetBoundingBox() const
{
	Polygonn* polygon = polygons;
	BoundingBox<float> box = polygon->GetBoundingBox();
	++polygon;

	//loop through all our vertices
	for(; polygon != polygons + nPolies; ++polygon)
	{
		box.ResizeToFit(box);
	}

	return box;
}
/****************************************************************************/
/*!
\brief
returns the vector of polygons
*/
/****************************************************************************/
Polygonn* Mesh::GetPolyBuffer()
{
	return polygons;
}
/****************************************************************************/
/*!
\brief
returns the number of polygons
*/
/****************************************************************************/
const unsigned& Mesh::GetNPolies() const
{
	return nPolies;
}