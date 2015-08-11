#include "Octree.h"
#include "timer.h"
/****************************************************************************/
/*!
\file Octree.cpp
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
An octree made specifically for voxels
*/
/****************************************************************************/

/****************************************************************************/
/*!
\brief
Default constructor
\param diameter
		the diameter of our tree
\param displacement
		the displacement of our tree in the world
*/
/****************************************************************************/
Octree::Octree(int diameter, Vector3 displacement, int subdivisionLimit)
	:
diameter(diameter),
displacement(displacement),
subdivisionLimit(subdivisionLimit)
{
	subdivisions = new OctreeLeaf[subdivisionLimit];
	currentSubdivisionSet = subdivisions;
	mainLeaf.Set(this);
	SetRangeTo(diameter, displacement);
}
/****************************************************************************/
/*!
\brief
Default destructor
*/
/****************************************************************************/
Octree::~Octree()
{
	delete [] subdivisions;
}


OctreeLeaf* Octree::GetSubdivisions()
{
	if((currentSubdivisionSet - subdivisions) >= subdivisionLimit)
	{
		throw;
	}
	OctreeLeaf* current = currentSubdivisionSet;
	currentSubdivisionSet += 8;
	return current;
}

/****************************************************************************/
/*!
\brief
Sets the first leaf to this range if it has not been initialised yet
\param diameter
		the diameter of the first leaf
\param displacement
		the displacement of the leaf in the world
*/
/****************************************************************************/
void Octree::SetRangeTo(int diameter, Vector3 displacement)
{
	this->diameter = diameter;
	this->displacement = displacement;
	Range<int> fullRangeX(1,1);
	Range<int> fullRangeY(1,1);
	Range<int> fullRangeZ(1,1);
	while(fullRangeX.Length() < diameter)
	{
		int newEnd = fullRangeX.end * 2;
		fullRangeX.end = newEnd;
		fullRangeY.end = newEnd;
		fullRangeZ.end = newEnd;
	}
	diameter = fullRangeX.Length();
	fullRangeX.Set(fullRangeX.start + displacement.x - 1, fullRangeX.end + displacement.x - 1);
	fullRangeY.Set(fullRangeY.start + displacement.y - 1, fullRangeY.end + displacement.y - 1);
	fullRangeZ.Set(fullRangeZ.start + displacement.z - 1, fullRangeZ.end + displacement.z - 1);
	mainLeaf.SetBoundingBoxTo(BoundingBox<int>(fullRangeX, fullRangeY, fullRangeZ));
}
/****************************************************************************/
/*!
\brief
Returns the radius of the tree
*/
/****************************************************************************/
int Octree::GetRadius() const
{
	return mainLeaf.GetRadius();
}
/****************************************************************************/
/*!
\brief
Add a voxel to the tree
\param voxel
		the voxel to be added
*/
/****************************************************************************/
void Octree::AddNode(const BoundingBox<int>& box, const Polygonn& data)
{
	AddNode(OctreeNode(box, data));
}

void Octree::AddNode(const OctreeNode& node)
{
	mainLeaf.AddNode(node);
}

/****************************************************************************/
/*!
\brief
Returns the voxel at the specified position
\param position
		specifies the position of the voxel
*/
/****************************************************************************/
void Octree::GetData(const BoundingBox<int>& box, Polygonn** data_buffer, Polygonn*** data_buffer_end)
{
	GetData(OctreeNode(box), data_buffer, data_buffer_end);
}

void Octree::GetData(const OctreeNode& node, Polygonn** data_buffer, Polygonn*** data_buffer_end)
{
	BoundingBox<int> box(mainLeaf.GetRangeX(), mainLeaf.GetRangeY(), mainLeaf.GetRangeZ());

	if(!box.IsOverlapping(node.box))
	{
		return;
	}

	mainLeaf.GetData(node, data_buffer, data_buffer_end);
}