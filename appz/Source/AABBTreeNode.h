#pragma once
#include "BoundingBox.h"
#include "Polygon.h"
#include "CollisionBody.h"
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

typedef BoundingBox<float> AABBBox;

class AABBTreeNode
{
public:
	AABBTreeNode(const Polygonn& data = Polygonn());
	~AABBTreeNode();

	AABBBox box;
	Polygonn data;
	CollisionBody* body;
};