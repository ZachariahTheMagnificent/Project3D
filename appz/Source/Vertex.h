#pragma once
/****************************************************************************/
/*!
\file Vertex.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class used to store vertex values
*/
/****************************************************************************/
#include "Vector3.h"
#include "Vector2.h"
#include "D3DColor.h"
/****************************************************************************/
/*!
Class Vertex:
\brief
Stores vertex values
*/
/****************************************************************************/
class Vertex 
{
public:
	Vertex(const Vector3& pos = Vector3(), const Color& color = Color(), const Vector3& normal = Vector3(), const Vector2& texCoord = Vector2());
	~Vertex();
	void Set(const Vector3& pos, const Color& color, const Vector3& normal, const Vector2& texCoord);
	bool operator<(const Vertex& someOtherVertex) const;

	Vector3 pos;
	Color color;
	Vector3 normal;
	Vector2 texCoord;
};