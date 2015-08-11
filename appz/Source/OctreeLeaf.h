#pragma once
/****************************************************************************/
/*!
\file VoxelLeaf.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A node in the voxelOctree
*/
/****************************************************************************/
#include <iostream>
#include <vector>
#include "OctreeNode.h"
/****************************************************************************/
/*!
\brief
the default ranges of our leaf
*/
/****************************************************************************/
const int VoxelLeafMinn = INT_MIN/16;
const int VoxelLeafMaxx = INT_MAX/16;
/****************************************************************************/
/*!
Class VoxelLeaf:
\brief
A node in the voxelOctree
*/
/****************************************************************************/
class Octree;

class OctreeLeaf
{
public:
	OctreeLeaf(const BoundingBox<int>& box = BoundingBox<int>(Range<int>(VoxelLeafMinn, VoxelLeafMaxx), Range<int>(VoxelLeafMinn, VoxelLeafMaxx), Range<int>(VoxelLeafMinn, VoxelLeafMaxx)));
	~OctreeLeaf();
	void Set(Octree* tree, const BoundingBox<int>& box = BoundingBox<int>(Range<int>(VoxelLeafMinn, VoxelLeafMaxx), Range<int>(VoxelLeafMinn, VoxelLeafMaxx), Range<int>(VoxelLeafMinn, VoxelLeafMaxx)));
	void SetBoundingBoxTo(const BoundingBox<int>& box);
	const Range<int>& GetRangeX() const;
	const Range<int>& GetRangeY() const;
	const Range<int>& GetRangeZ() const;
	Range<int> GetLowerRangeX() const;
	Range<int> GetLowerRangeY() const;
	Range<int> GetLowerRangeZ() const;
	Range<int> GetUpperRangeX() const;
	Range<int> GetUpperRangeY() const;
	Range<int> GetUpperRangeZ() const;
	BoundingBox<int> GetBox1() const;
	BoundingBox<int> GetBox2() const;
	BoundingBox<int> GetBox3() const;
	BoundingBox<int> GetBox4() const;
	BoundingBox<int> GetBox5() const;
	BoundingBox<int> GetBox6() const;
	BoundingBox<int> GetBox7() const;
	BoundingBox<int> GetBox8() const;
	void AddNode(const OctreeNode& node);
	void GetData(const OctreeNode& testNode, Polygonn** data_buffer, Polygonn*** data_buffer_end);
	void Subdivide();
	bool HasAlreadySubdivided() const;
	bool IsEmpty() const;
	int GetRadius() const;
	
private:
	unsigned GetIndex(const OctreeNode& node) const;
	unsigned char CheckCollisionWithBoxes(const OctreeNode& testNode) const;
	
	BoundingBox<int> box;

	OctreeLeaf* leaves;
	Octree* tree;
	std::vector<OctreeNode> nodes;
};