#pragma once
#include "BoundingBox.h"
#include "Polygon.h"
/****************************************************************************/
/*!
\file OctreeNode.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class used to store and handle OctreeNode information
*/
/****************************************************************************/

/****************************************************************************/
/*!
Class OctreeNode:
\brief
Used to store and handle OctreeNode information
*/
/****************************************************************************/

class OctreeNode
{
public:
	OctreeNode(const BoundingBox<int>& box = BoundingBox<int>(), const Polygonn& data = Polygonn());
	~OctreeNode();

	BoundingBox<int> box;
	Polygonn data;
};