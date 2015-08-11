#pragma once
/****************************************************************************/
/*!
\file Polygon.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class used store and handle polygon values
*/
/****************************************************************************/
#include "Vertex.h"
#include "MatrixStack.h"
#include "BoundingBox.h"
/****************************************************************************/
/*!
Class Polygonn:
\brief
Stores and handles polygon values
*/
/****************************************************************************/
class Polygonn
{
public:
	Polygonn(const Vertex& initVertex1 = Vertex(), const Vertex& initVertex2 = Vertex(), const Vertex& initVertex3 = Vertex());
	~Polygonn();

	void Set(const Vertex& initVertex1, const Vertex& initVertex2, const Vertex& initVertex3);

	bool NormalIsFacing(const Vertex& vert) const;
	bool OppositeNormalIsFacing(const Vertex& vert) const;
	bool Intersects(Polygonn& polygon) const;
	bool Intersects(Vector3& line, Vector3 displacement) const;

	BoundingBox<float> GetBoundingBox() const;
	Vector3 GetCentre() const;
	Vector3 GetNormal() const;
	Vector3 GetEdge1() const;
	Vector3 GetEdge2() const;
	Vector3 GetEdge3() const;
	Polygonn Flipped() const;

	void MoveAlongNormalBy(const float displacement);
	void MoveBy(Mtx44 matrix);

	Vertex vertex1, vertex2, vertex3;
};