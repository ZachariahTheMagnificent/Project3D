#include "Mesh.h"
#include <limits>
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
{
	SetSize(nPolies);
}
/****************************************************************************/
/*!
\brief
default destructor
*/
/****************************************************************************/
Mesh::~Mesh()
{
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
MeshBox Mesh::GetBoundingBox() const
{
	//set the bounding box to the most extreme values so that the polygon's most extreme values will be stored.
	BoundingBox<float> box(Range<float>(FLT_MAX, -FLT_MAX), Range<float>(FLT_MAX, -FLT_MAX), Range<float>(FLT_MAX, -FLT_MAX));

	//loop through all our vertices
	for(Polygonn* polygon = GetBegin(), *end = GetEnd(); polygon != end; ++polygon)
	{
		box.ResizeToFit(box);
	}

	return box;
}