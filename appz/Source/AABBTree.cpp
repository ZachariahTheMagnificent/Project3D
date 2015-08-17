#include "AABBTree.h"

AABBTree::AABBTree(const unsigned& size)
	:
capacity(size),
nodes(NULL)
{
	if(size)
	{
		nodes = new AABBTreeNode[size];
	}
}

AABBTree::~AABBTree()
{
	delete [] nodes;
}

void AABBTree::IncreaseCapacityTo(const unsigned& size)
{
	if(size == 0)
	{
		throw;
	}

	if(size > capacity)
	{
		delete [] nodes;
		nodes = NULL;

		capacity = size;
		nodes = new AABBTreeNode[capacity];
	}
}

void AABBTree::Sort(const AABBBox& box, const unsigned& size)
{
	if(size > capacity)
	{
		throw;
	}

	AABBTreeNode* begin = nodes;
	AABBTreeNode* end = begin + size - 1;

	mainLeaf.Sort2(box, begin, end);
	//mainLeaf.Sort3(box, begin, end);
}

void AABBTree::GetContacts(AABBTree* tree, Contact* buffer, Contact** end)
{
	*end = buffer;
	//mainLeaf.GetContacts(&tree->mainLeaf, end);
}

AABBTreeNode* AABBTree::GetBegin()
{
	return nodes;
}

AABBTreeNode* AABBTree::GetEnd()
{
	return nodes + capacity;
}

void AABBTree::GetContacts(Contact** iterator)
{
	mainLeaf.GetContacts(iterator);
}