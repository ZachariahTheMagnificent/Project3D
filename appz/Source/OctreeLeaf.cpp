#include "OctreeLeaf.h"
#include "timer.h"
#include "Octree.h"
/****************************************************************************/
/*!
\file OctreeLeaf.cpp
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A node in the voxelOctree
*/
/****************************************************************************/

/****************************************************************************/
/*!
\brief
Default constructor
\param rangeX
		the x-range of the leaf
\param rangeY
		the y-range of the leaf
\param rangeZ
		the z-range of the leaf
\param parent
		a pointer to the leaf above it in the hierarachy
*/
/****************************************************************************/
OctreeLeaf::OctreeLeaf(const BoundingBox<int>& box)
	:
box(box),
leaves(NULL)
{
}
/****************************************************************************/
/*!
\brief
Sets the range of the voxel if it has not been used yet
\param rangeX
		sets the x-range of the leaf
\param rangeY
		sets the y-range of the leaf
\param rangeZ
		sets the z-range of the leaf
*/
/****************************************************************************/
void OctreeLeaf::SetBoundingBoxTo(const BoundingBox<int>& box)
{
	this->box = box;
}

void OctreeLeaf::Set(Octree* tree, const BoundingBox<int>& box)
{
	if(tree)
	{
		this->tree = tree;
	}
	SetBoundingBoxTo(box);
}
/****************************************************************************/
/*!
\brief
Default destructor
*/
/****************************************************************************/
OctreeLeaf::~OctreeLeaf()
{
}
/****************************************************************************/
/*!
\brief
Add a voxel to the leaf
*/
/****************************************************************************/
void OctreeLeaf::AddNode(const OctreeNode& node)
{
	unsigned index = GetIndex(node);
	//if index overlaps more than one node
	if(index == 8)
	{
		nodes.push_back(node);
	}
	else if(HasAlreadySubdivided())
	{
		leaves[index].AddNode(node);
	}
	//if we can still subdivide 
	else if(box.rangeX.Length() >= 2)
	{
		Subdivide();
		leaves[index].AddNode(node);
	}
	else
	{
		nodes.push_back(node);
	}
}
/****************************************************************************/
/*!
\brief
Returns the x-range of the leaf
*/
/****************************************************************************/
const Range<int>& OctreeLeaf::GetRangeX() const
{
	return box.rangeX;
}
/****************************************************************************/
/*!
\brief
Returns the y-range of the leaf
*/
/****************************************************************************/
const Range<int>& OctreeLeaf::GetRangeY() const
{
	return box.rangeY;
}
/****************************************************************************/
/*!
\brief
Returns the z-range of the leaf
*/
/****************************************************************************/
const Range<int>& OctreeLeaf::GetRangeZ() const
{
	return box.rangeZ;
}

Range<int> OctreeLeaf::GetLowerRangeX() const
{
	int midpointX = box.rangeX.MidPoint();
	return Range<int>(box.rangeX.start, midpointX);
}

Range<int> OctreeLeaf::GetLowerRangeY() const
{
	int midpointY = box.rangeY.MidPoint();
	return Range<int>(box.rangeY.start, midpointY);
}

Range<int> OctreeLeaf::GetLowerRangeZ() const
{
	int midpointZ = box.rangeZ.MidPoint();
	return Range<int>(box.rangeZ.start, midpointZ);
}

Range<int> OctreeLeaf::GetUpperRangeX() const
{
	int midpointX = box.rangeX.MidPoint();
	return Range<int>(midpointX + 1, box.rangeX.end);
}

Range<int> OctreeLeaf::GetUpperRangeY() const
{
	int midpointY = box.rangeY.MidPoint();
	return Range<int>(midpointY + 1, box.rangeY.end);
}

Range<int> OctreeLeaf::GetUpperRangeZ() const
{
	int midpointZ = box.rangeZ.MidPoint();
	return Range<int>(midpointZ + 1, box.rangeZ.end);
}

/****************************************************************************/
/*!
\brief
Returns a voxel at the specified position
\param position
		the specified position of the voxel
*/
/****************************************************************************/
BoundingBox<int> OctreeLeaf::GetBox1() const
{
	return BoundingBox<int>(GetLowerRangeX(), GetLowerRangeY(), GetLowerRangeZ());
}

BoundingBox<int> OctreeLeaf::GetBox2() const
{
	return BoundingBox<int>(GetLowerRangeX(), GetLowerRangeY(), GetUpperRangeZ());
}

BoundingBox<int> OctreeLeaf::GetBox3() const
{
	return BoundingBox<int>(GetLowerRangeX(), GetUpperRangeY(), GetLowerRangeZ());
}

BoundingBox<int> OctreeLeaf::GetBox4() const
{
	return BoundingBox<int>(GetLowerRangeX(), GetUpperRangeY(), GetUpperRangeZ());
}

BoundingBox<int> OctreeLeaf::GetBox5() const
{
	return BoundingBox<int>(GetUpperRangeX(), GetLowerRangeY(), GetLowerRangeZ());
}

BoundingBox<int> OctreeLeaf::GetBox6() const
{
	return BoundingBox<int>(GetUpperRangeX(), GetLowerRangeY(), GetUpperRangeZ());
}

BoundingBox<int> OctreeLeaf::GetBox7() const
{
	return BoundingBox<int>(GetUpperRangeX(), GetUpperRangeY(), GetLowerRangeZ());
}

BoundingBox<int> OctreeLeaf::GetBox8() const
{
	return BoundingBox<int>(GetUpperRangeX(), GetUpperRangeY(), GetUpperRangeZ());
}

void OctreeLeaf::GetData(const OctreeNode& testNode, Polygonn** data_buffer, Polygonn*** data_buffer_end)
{
	unsigned char collisionCheck = CheckCollisionWithBoxes(testNode);

	for(std::vector<OctreeNode>::iterator node = nodes.begin(), end = nodes.end(); node != end; ++node)
	{
		if(node->box.IsOverlapping(testNode.box))
		{
			*data_buffer = &node->data;
			*data_buffer_end = ++data_buffer;
		}
	}
	if(HasAlreadySubdivided())
	{
		if(collisionCheck & 0x01)
		{
			leaves[1].GetData(testNode, data_buffer, data_buffer_end);
		}
		if(collisionCheck & 0x02)
		{
			leaves[2].GetData(testNode, data_buffer, data_buffer_end);
		}
		if(collisionCheck & 0x04)
		{
			leaves[3].GetData(testNode, data_buffer, data_buffer_end);
		}
		if(collisionCheck & 0x08)
		{
			leaves[4].GetData(testNode, data_buffer, data_buffer_end);
		}
		if(collisionCheck & 0x10)
		{
			leaves[5].GetData(testNode, data_buffer, data_buffer_end);
		}
		if(collisionCheck & 0x20)
		{
			leaves[6].GetData(testNode, data_buffer, data_buffer_end);
		}
		if(collisionCheck & 0x40)
		{
			leaves[7].GetData(testNode, data_buffer, data_buffer_end);
		}
		if(collisionCheck & 0x80)
		{
			leaves[8].GetData(testNode, data_buffer, data_buffer_end);
		}
	}
}
/****************************************************************************/
/*!
\brief
Subdivides the leaf into more leaves
*/
/****************************************************************************/
void OctreeLeaf::Subdivide()
{
	Range<int> lowerRangeX = GetLowerRangeX(), upperRangeX = GetUpperRangeX(),
		lowerRangeY = GetLowerRangeY(), upperRangeY = GetUpperRangeY(),
		lowerRangeZ = GetLowerRangeZ(), upperRangeZ = GetUpperRangeZ();

	leaves = tree->GetSubdivisions();
	OctreeLeaf* leaf = leaves;

	leaf->Set(tree, GetBox1());
	++leaf;
	leaf->Set(tree, GetBox2());
	++leaf;
	leaf->Set(tree, GetBox3());
	++leaf;
	leaf->Set(tree, GetBox4());
	++leaf;
	leaf->Set(tree, GetBox5());
	++leaf;
	leaf->Set(tree, GetBox6());
	++leaf;
	leaf->Set(tree, GetBox7());
	++leaf;
	leaf->Set(tree, GetBox8());
	++leaf;
}
/****************************************************************************/
/*!
\brief
Returns a bool to whether or not the leaf has already subdivided
*/
/****************************************************************************/
bool OctreeLeaf::HasAlreadySubdivided() const
{
	return leaves;
}
/****************************************************************************/
/*!
\brief
Returns a bool to whether or not the leaf is empty
*/
/****************************************************************************/
bool OctreeLeaf::IsEmpty() const
{
	return nodes.empty() && !HasAlreadySubdivided();
}
/****************************************************************************/
/*!
\brief
Turns a position into an index
\param position
		the position used to get an index
*/
/****************************************************************************/


unsigned char OctreeLeaf::CheckCollisionWithBoxes(const OctreeNode& testNode) const
{
	unsigned char returnValue = 0;
	
	if(testNode.box.IsOverlapping(GetBox1()))
	{
		returnValue = returnValue | 0x01;
	}
	if(testNode.box.IsOverlapping(GetBox2()))
	{
		returnValue = returnValue | 0x02;
	}
	if(testNode.box.IsOverlapping(GetBox3()))
	{
		returnValue = returnValue | 0x04;
	}
	if(testNode.box.IsOverlapping(GetBox4()))
	{
		returnValue = returnValue | 0x08;
	}
	if(testNode.box.IsOverlapping(GetBox5()))
	{
		returnValue = returnValue | 0x10;
	}
	if(testNode.box.IsOverlapping(GetBox6()))
	{
		returnValue = returnValue | 0x20;
	}
	if(testNode.box.IsOverlapping(GetBox7()))
	{
		returnValue = returnValue | 0x40;
	}
	if(testNode.box.IsOverlapping(GetBox8()))
	{
		returnValue = returnValue | 0x80;
	}
	return returnValue;
}

unsigned OctreeLeaf::GetIndex(const OctreeNode& node) const
{
	unsigned x,y,z;

	Range<int> testRangeX = node.box.rangeX,
		testRangeY = node.box.rangeY,
		testRangeZ = node.box.rangeZ;

	Range<int> lowerRangeX = GetLowerRangeX(), upperRangeX = GetUpperRangeX(),
		lowerRangeY = GetLowerRangeY(), upperRangeY = GetUpperRangeY(),
		lowerRangeZ = GetLowerRangeZ(), upperRangeZ = GetUpperRangeZ();

	if(lowerRangeX.IsInRange(testRangeX) && upperRangeX.IsInRange(testRangeX))
	{
		return 8;
	}
	else if(lowerRangeX.IsInRange(testRangeX))
	{
		x = 0;
	}
	else if(upperRangeX.IsInRange(testRangeX))
	{
		x = 1;
	}
	else
	{
		throw;
	}
	
	if(lowerRangeY.IsInRange(testRangeY) && upperRangeY.IsInRange(testRangeY))
	{
		return 8;
	}
	else if(lowerRangeY.IsInRange(testRangeY))
	{
		y = 0;
	}
	else if(upperRangeY.IsInRange(testRangeY))
	{
		y = 1;
	}
	else
	{
		throw;
	}
	
	if(lowerRangeZ.IsInRange(testRangeZ) && upperRangeZ.IsInRange(testRangeZ))
	{
		return 8;
	}
	else if(lowerRangeZ.IsInRange(testRangeZ))
	{
		z = 0;
	}
	else if(upperRangeZ.IsInRange(testRangeZ))
	{
		z = 1;
	}
	else
	{
		throw;
	}

	return x*4 + y*2 + z;
}
/****************************************************************************/
/*!
\brief
returns the radius of the leaf
*/
/****************************************************************************/
int OctreeLeaf::GetRadius() const
{
	return box.rangeX.Length() * 0.5;
}