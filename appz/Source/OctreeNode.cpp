#include "OctreeNode.h"
/****************************************************************************/
/*!
\file OctreeNode.cpp
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class used to store and handle OctreeNode information
*/
/****************************************************************************/
OctreeNode::OctreeNode(const BoundingBox<int>& box, const Polygonn& data)
	:
box(box),
data(data)
{
}

OctreeNode::~OctreeNode()
{
}