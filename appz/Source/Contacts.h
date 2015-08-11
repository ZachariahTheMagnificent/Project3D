#pragma once
#include "AABBTreeNode.h"
/****************************************************************************/
/*!
\file Contact.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class used handle contacts
*/
/****************************************************************************/
class CollisionBody;
/****************************************************************************/
/*!
Class Contact:
\brief
Used handle contacts
*/
/****************************************************************************/
class Contact
{
public:
	Contact(AABBTreeNode* node1 = NULL, AABBTreeNode* node2 = NULL);
	~Contact();
	void Set(AABBTreeNode* node1, AABBTreeNode* node2);
	bool IsStillValid();
	void ResolveAccordingTo(const double deltaTime);
	bool operator<(const Contact& contact) const;
	bool operator>(const Contact& contact) const;
	bool operator<=(const Contact& contact) const;
	bool operator>=(const Contact& contact) const;
	bool operator==(const Contact& contact) const;

	AABBTreeNode* node1;
	AABBTreeNode* node2;
};