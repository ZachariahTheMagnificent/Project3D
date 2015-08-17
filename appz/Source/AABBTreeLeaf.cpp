#include "AABBTreeLeaf.h"
#include "AABBTree.h"

AABBTreeLeaf::AABBTreeLeaf()
	:
begin(NULL),
end(NULL),
leaves(NULL)
{
}

AABBTreeLeaf::~AABBTreeLeaf(void)
{
	if(leaves)
	{
		delete [] leaves;
		leaves = NULL;
	}
}

const AABBBox& AABBTreeLeaf::GetBox() const
{
	return box;
}

unsigned AABBTreeLeaf::GetSize()
{
	if(begin == NULL)
	{
		return 0;
	}
	return end - begin + 1;
}

AABBTreeNode* AABBTreeLeaf::GetBegin()
{
	return begin;
}

AABBTreeNode* AABBTreeLeaf::GetEnd()
{
	return end;
}

void AABBTreeLeaf::DumpData()
{
	begin = NULL;
	end = NULL;
}

void AABBTreeLeaf::Sort1(const AABBBox& box, AABBTreeNode* begin, AABBTreeNode* end)
{
	this->begin = begin;
	this->end = end;
	this->box = box;

	if(!HasAlreadySubdivided())
	{
		leaves = new AABBTreeLeaf[TOTAL_LEAVES];
	}
}

void AABBTreeLeaf::Sort2(const AABBBox& box, AABBTreeNode* begin, AABBTreeNode* end)
{
	this->begin = begin;
	this->end = end;
	this->box = box;

	if(!HasAlreadySubdivided())
	{
		leaves = new AABBTreeLeaf[TOTAL_LEAVES];
	}

	//if there is only one node left
	if(end == begin)
	{
		if(!leaves[LEFT].IsEmpty())
		{
			leaves[LEFT].DumpData();
			leaves[RIGHT].DumpData();
		}
		return;
	}

	AABBBox leftBox;
	AABBBox rightBox;
	AABBTreeNode* leftEnd = begin + (end - begin)/2;
	AABBTreeNode* rightEnd = end;

	for(AABBTreeNode* node = begin; node != leftEnd + 1; ++node)
	{
		leftBox.ResizeToFit(node->box);
	}
	for(AABBTreeNode* node = leftEnd + 1; node != rightEnd + 1; ++node)
	{
		rightBox.ResizeToFit(node->box);
	}

	leaves[LEFT].Sort2(leftBox, begin, leftEnd);
	leaves[RIGHT].Sort2(rightBox, leftEnd + 1, rightEnd);
}

void AABBTreeLeaf::Sort3(const AABBBox& box, AABBTreeNode* begin, AABBTreeNode* end, unsigned char avaliableAxis)
{
	this->begin = begin;
	this->end = end;
	this->box = box;

	const unsigned char xFlag = 0x01;
	const unsigned char yFlag = 0x02;
	const unsigned char zFlag = 0x04;


	if(!HasAlreadySubdivided())
	{
		leaves = new AABBTreeLeaf[TOTAL_LEAVES];
	}

	//if there is only one node left
	if(end == begin)
	{
		if(!leaves[LEFT].IsEmpty())
		{
			leaves[LEFT].DumpData();
			leaves[RIGHT].DumpData();
		}
		return;
	}

	AABBBox leftBox;
	AABBBox rightBox;
	AABBTreeNode* leftNodeEnd = begin - 1;

	float split = 0;
	const unsigned size = GetSize();

	if((avaliableAxis & xFlag) && (box.rangeX.Length() >= box.rangeY.Length() || !(avaliableAxis & yFlag)) && (box.rangeX.Length() >= box.rangeZ.Length() || (avaliableAxis & zFlag)))
	{
		for(AABBTreeNode* node = begin; node != begin + size; ++node)
		{
			const float midPoint = node->box.rangeX.MidPoint();
			split += midPoint;
		}

		split /= size;
		for(AABBTreeNode* node = begin; node != begin + size; ++node)
		{
			if(node->box.rangeX.MidPoint() <= split)
			{
				leftBox.ResizeToFit(node->box);

				++leftNodeEnd;

				AABBTreeNode temp = *leftNodeEnd;
				*leftNodeEnd = *node;
				*node = temp;
			}
			else
			{
				rightBox.ResizeToFit(node->box);
			}
		}
		
		if(leftNodeEnd == begin - 1 || leftNodeEnd == end)
		{
			Sort3(box, begin, end, avaliableAxis & (yFlag | zFlag));
			return;
		}
		leaves[LEFT].Sort3(leftBox, begin, leftNodeEnd, avaliableAxis);
		leaves[RIGHT].Sort3(rightBox, leftNodeEnd + 1, end, avaliableAxis);
	}
	else if((avaliableAxis & yFlag) && (box.rangeY.Length() >= box.rangeZ.Length() || !(avaliableAxis & zFlag)))
	{
		for(AABBTreeNode* node = begin; node != begin + size; ++node)
		{
			const float midPoint = node->box.rangeY.MidPoint();
			split += midPoint;
		}

		split /= size;
		for(AABBTreeNode* node = begin; node != begin + size; ++node)
		{
			if(node->box.rangeY.MidPoint() <= split)
			{
				leftBox.ResizeToFit(node->box);

				++leftNodeEnd;

				AABBTreeNode temp = *leftNodeEnd;
				*leftNodeEnd = *node;
				*node = temp;
			}
			else
			{
				rightBox.ResizeToFit(node->box);
			}
		}
		
		if(leftNodeEnd == begin - 1 || leftNodeEnd == end)
		{
			Sort3(box, begin, end, avaliableAxis & (xFlag | zFlag));
			return;
		}
		leaves[LEFT].Sort3(leftBox, begin, leftNodeEnd, avaliableAxis);
		leaves[RIGHT].Sort3(rightBox, leftNodeEnd + 1, end, avaliableAxis);
	}
	else if(avaliableAxis & zFlag)
	{
		for(AABBTreeNode* node = begin; node != begin + size; ++node)
		{
			const float midPoint = node->box.rangeZ.MidPoint();
			split += midPoint;
		}

		split /= size;
		for(AABBTreeNode* node = begin; node != begin + size; ++node)
		{
			if(node->box.rangeZ.MidPoint() <= split)
			{
				leftBox.ResizeToFit(node->box);

				++leftNodeEnd;

				AABBTreeNode temp = *leftNodeEnd;
				*leftNodeEnd = *node;
				*node = temp;
			}
			else
			{
				rightBox.ResizeToFit(node->box);
			}
		}
		
		if(leftNodeEnd == begin - 1 || leftNodeEnd == end)
		{
			Sort3(box, begin, end, avaliableAxis & (xFlag | yFlag));
			return;
		}
		leaves[LEFT].Sort3(leftBox, begin, leftNodeEnd, avaliableAxis);
		leaves[RIGHT].Sort3(rightBox, leftNodeEnd + 1, end, avaliableAxis);
	}
	else
	{
		leaves[LEFT].DumpData();
		leaves[RIGHT].DumpData();
	}
}

AABBTreeLeaf* AABBTreeLeaf::GetLeaf(const AABBBox& box)
{
	if(leaves[LEFT].IsEmpty())
	{
		return this;
	}

	bool hitsLeft = leaves[LEFT].box.IsOverlapping(box);
	bool hitsRight = leaves[RIGHT].box.IsOverlapping(box);

	if(hitsLeft && hitsRight)
	{
		return this;
	}
	if(hitsLeft)
	{
		return leaves[LEFT].GetLeaf(box);
	}
	if(hitsRight)
	{
		return leaves[RIGHT].GetLeaf(box);
	}

	return NULL;
}

void AABBTreeLeaf::GetContacts(AABBTreeNode* node, Contact** iterator)
{
	if(leaves[LEFT].IsEmpty())
	{
		unsigned size = GetSize();
		for(AABBTreeNode* ourNode = begin; ourNode != begin + size; ++ourNode)
		{
   			if(node->box.IsOverlapping(ourNode->box))
			{
				(*iterator)->node2 = ourNode;
				(*iterator)->node1 = node;
				++(*iterator);
			}
		}
	}
	if(leaves[LEFT].box.IsOverlapping(node->box))
	{
		leaves[LEFT].GetContacts(node, iterator);
	}
	if(leaves[RIGHT].box.IsOverlapping(node->box))
	{
		leaves[RIGHT].GetContacts(node, iterator);
	}
}

void AABBTreeLeaf::GetContacts(AABBTreeLeaf* leaf, Contact** iterator)
{
	if(leaves[LEFT].IsEmpty())
	{
		leaf = leaf->GetLeaf(box);
		unsigned size = GetSize();
		for(AABBTreeNode* node = begin; node != begin + size; ++node)
		{
			leaf->GetContacts(node, iterator);
		}
		return;
	}

	bool hitsLeft = leaf->leaves[LEFT].box.IsOverlapping(box);
	bool hitsRight = leaf->leaves[RIGHT].box.IsOverlapping(box);

	if(hitsLeft && hitsRight || leaf->leaves[LEFT].IsEmpty())
	{
		if(leaves[LEFT].box.IsOverlapping(leaf->box))
		{
			leaves[LEFT].GetContacts(leaf, iterator);
		}
		if(leaves[RIGHT].box.IsOverlapping(leaf->box))
		{
			leaves[RIGHT].GetContacts(leaf, iterator);
		}
	}
	else
	{
		if(hitsLeft)
		{
			GetContacts(&leaf->leaves[LEFT], iterator);
		}
		else if(hitsRight)
		{
			GetContacts(&leaf->leaves[RIGHT], iterator);
		}
	}
}

bool AABBTreeLeaf::HasAlreadySubdivided() const
{
	return leaves;
}

bool AABBTreeLeaf::IsEmpty() const
{
	return begin == NULL;
}