#pragma once
#include "AABBTreeNode.h"
#include "Contacts.h"
#include <vector>

class AABBTreeLeaf
{
private:
	enum SPLIT
	{
		X_SPLIT,
		Y_SPLIT,
		Z_SPLIT,
		TOTAL_SPLITS
	};

public:
	AABBTreeLeaf();
	~AABBTreeLeaf();
	void DumpData();
	unsigned GetSize();
	AABBTreeNode* GetBegin();
	AABBTreeNode* GetEnd();
	void Sort1(const AABBBox& box, AABBTreeNode* begin, AABBTreeNode* end);
	void Sort2(const AABBBox& box, AABBTreeNode* begin, AABBTreeNode* end);
	void Sort3(const AABBBox& box, AABBTreeNode* begin, AABBTreeNode* end, unsigned char avaliableAxis);
	AABBTreeLeaf* GetLeaf(const AABBBox& box);
	void GetContacts(AABBTreeNode* node, Contact** iterator);
	void GetContacts(AABBTreeLeaf* leaf, Contact** iterator);
	bool HasAlreadySubdivided() const;
	bool IsEmpty() const;
	const AABBBox& GetBox() const;
private:
	AABBBox box;
	AABBTreeNode* begin;
	AABBTreeNode* end;
	AABBTreeLeaf* leaves;

	enum LEAVES
	{
		LEFT,
		RIGHT,
		TOTAL_LEAVES
	};
};