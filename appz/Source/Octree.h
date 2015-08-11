#pragma once
/****************************************************************************/
/*!
\file VoxelOctree.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
An octree made specifically for voxels
*/
/****************************************************************************/
#include "OctreeLeaf.h"
#include "Vector3.h"
/****************************************************************************/
/*!
Class VoxelOctree:
\brief
An octree made specifically for voxels
*/
/****************************************************************************/
class Octree
{
public:
	Octree(int diameter = 0, Vector3 displacement = Vector3(), int subdivisionLimit = 1600);
	~Octree();
	void SetRangeTo(int diameter, Vector3 displacement);
	void AddNode(const BoundingBox<int>& box, const Polygonn& data);
	void AddNode(const OctreeNode& node);
	void GetData(const BoundingBox<int>& box, Polygonn** data_buffer, Polygonn*** data_buffer_end);
	void GetData(const OctreeNode& node, Polygonn** data_buffer, Polygonn*** data_buffer_end);
	int GetRadius() const;
	OctreeLeaf* GetSubdivisions();
	OctreeLeaf* currentSubdivisionSet;
	OctreeLeaf* subdivisions;
private:
	OctreeLeaf mainLeaf;
	int diameter;
	const int subdivisionLimit;
	Vector3 displacement;
};