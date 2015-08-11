#include "Polygon.h"
/****************************************************************************/
/*!
\file Polygon.h
\author Muhammad Shafik Bin Mazlinan
\par email: cyboryxmen@yahoo.com
\brief
A class used to see if a value is within a certain range
*/
/****************************************************************************/

/****************************************************************************/
/*!
\brief
Default constructor
\param initVertex1
initializes the first vertex
\param initVertex2
initializes the second vertex
\param initVertex3
initializes the first vertex
*/
/****************************************************************************/
Polygonn::Polygonn(const Vertex& initVertex1, const Vertex& initVertex2, const Vertex& initVertex3)
	:
vertex1(initVertex1),
vertex2(initVertex2),
vertex3(initVertex3)
{
}
/****************************************************************************/
/*!
\brief
default destructor
*/
/****************************************************************************/
Polygonn::~Polygonn()
{
}

/****************************************************************************/
/*!
\brief
Checks if the polygon intersects with teh given polygon
\param polygon
		polygon to be checked together with
*/
/****************************************************************************/
bool Polygonn::Intersects(Polygonn& polygon) const
{
	return polygon.Intersects(GetEdge1(),vertex1.pos) || polygon.Intersects(GetEdge2(),vertex2.pos) || polygon.Intersects(GetEdge3(),vertex3.pos) ||
		Intersects(polygon.GetEdge1(),polygon.vertex1.pos) || Intersects(polygon.GetEdge2(),polygon.vertex2.pos) || Intersects(polygon.GetEdge3(),polygon.vertex3.pos);
}

Vector3 Polygonn::GetCentre() const
{
	return (vertex1.pos + vertex2.pos + vertex3.pos)/3;
}

/****************************************************************************/
/*!
\brief
Checks if a given line intersects the polygon
\param line
		the gradient of the line to be checked against
\param displacement
		the displacement of the line to be checked against
*/
/****************************************************************************/
bool Polygonn::Intersects(Vector3& line, Vector3 displacement) const
{
	Vector3 normal = GetNormal();

	if(normal.IsZero())
	{
		return false;
	}

	//if the line is parallel to polygon
	if(Math::IsEqual(normal.Dot(line), 0))
	{
		return false;
	}

	float distanceFromOrgin = normal.Dot(vertex1.pos);
	float lineSegment = (normal.Dot(-displacement) + distanceFromOrgin)/(normal.Dot(line));

	//if the point of intersection is out of the line's range
	if(lineSegment < 0 || lineSegment > 1)
	{
		return false;
	}

	Vector3 pointOfIntersection;
	pointOfIntersection = displacement + line*lineSegment;

	Vector3 edgeNormal1 = GetEdge1().Cross(normal);
	Vector3 edgeNormal2 = GetEdge2().Cross(normal);
	Vector3 edgeNormal3 = GetEdge3().Cross(normal);

	Vector3 testVec1 = pointOfIntersection - vertex1.pos;
	Vector3 testVec2 = pointOfIntersection - vertex2.pos;
	Vector3 testVec3 = pointOfIntersection - vertex3.pos;
	if(edgeNormal1.Dot(testVec1) > 0 || edgeNormal2.Dot(testVec2) > 0 || edgeNormal3.Dot(testVec3) > 0)
	{
		return false;
	}

	return true;
}

void Polygonn::MoveBy(Mtx44 matrix)
{
	vertex1.pos = matrix * vertex1.pos;
	vertex2.pos = matrix * vertex2.pos;
	vertex3.pos = matrix * vertex3.pos;
}

/****************************************************************************/
/*!
\brief
Set function
\param initVertex1
initializes the first vertex
\param initVertex2
initializes the second vertex
\param initVertex3
initializes the first vertex
*/
/****************************************************************************/
void Polygonn::Set(const Vertex& initVertex1, const Vertex& initVertex2, const Vertex& initVertex3)
{
	vertex1 = initVertex1;
	vertex2 = initVertex2;
	vertex3 = initVertex3;
}
/****************************************************************************/
/*!
\brief
Checks if the normal of the polygon is facing a vertex
*/
/****************************************************************************/
bool Polygonn::NormalIsFacing(const Vertex& vert) const
{
	Vector3 normal = GetNormal();

	float distanceFromOrgin = -normal.Dot(vertex1.pos);
	float distanceToPoint = normal.Dot(vert.pos) + distanceFromOrgin;

	return distanceToPoint >= 0;
}
/****************************************************************************/
/*!
\brief
Checks if the normal of the polygon is facing the opposite direction of a vertex
*/
/****************************************************************************/
bool Polygonn::OppositeNormalIsFacing(const Vertex& vert) const
{
	Vector3 normal = -GetNormal();

	float distanceFromOrgin = -normal.Dot(vertex1.pos);
	float distanceToPoint = normal.Dot(vert.pos) + distanceFromOrgin;

	return distanceToPoint >= 0;
}
/****************************************************************************/
/*!
\brief
Get the bounds of the polygon
\param returnFurthestLeft
		a pointer to the location to store the polygon's furthest left
\param returnFurthestRight
		a pointer to the location to store the polygon's furthest right
\param returnFurthestDown
		a pointer to the location to store the polygon's furthest down
\param returnFurthestUp
		a pointer to the location to store the polygon's furthest up
\param returnFurthestBack
		a pointer to the location to store the polygon's furthest back
\param returnFurthestFront
		a pointer to the location to store the polygon's furthest front
*/
/****************************************************************************/
BoundingBox<float> Polygonn::GetBoundingBox() const
{
	BoundingBox<float> box;

	//range for x
	if(vertex1.pos.x <= vertex2.pos.x && vertex1.pos.x <= vertex3.pos.x)
	{
		box.rangeX.start = vertex1.pos.x;
	}
	else if(vertex2.pos.x <= vertex1.pos.x && vertex2.pos.x <= vertex3.pos.x)
	{
		box.rangeX.start = vertex2.pos.x;
	}
	else
	{
		box.rangeX.start = vertex3.pos.x;
	}

	if(vertex1.pos.x >= vertex2.pos.x && vertex1.pos.x >= vertex3.pos.x)
	{
		box.rangeX.end = vertex1.pos.x;
	}
	else if(vertex2.pos.x >= vertex1.pos.x && vertex2.pos.x >= vertex3.pos.x)
	{
		box.rangeX.end = vertex2.pos.x;
	}
	else
	{
		box.rangeX.end = vertex3.pos.x;
	}
	
	//range for y
	if(vertex1.pos.y <= vertex2.pos.y && vertex1.pos.y <= vertex3.pos.y)
	{
		box.rangeY.start = vertex1.pos.y;
	}
	else if(vertex2.pos.y <= vertex1.pos.y && vertex2.pos.y <= vertex3.pos.y)
	{
		box.rangeY.start = vertex2.pos.y;
	}
	else
	{
		box.rangeY.start = vertex3.pos.y;
	}

	if(vertex1.pos.y >= vertex2.pos.y && vertex1.pos.y >= vertex3.pos.y)
	{
		box.rangeY.end = vertex1.pos.y;
	}
	else if(vertex2.pos.y >= vertex1.pos.y && vertex2.pos.y >= vertex3.pos.y)
	{
		box.rangeY.end = vertex2.pos.y;
	}
	else
	{
		box.rangeY.end = vertex3.pos.y;
	}

	//range for z
	if(vertex1.pos.z <= vertex2.pos.z && vertex1.pos.z <= vertex3.pos.z)
	{
		box.rangeZ.start = vertex1.pos.z;
	}
	else if(vertex2.pos.z <= vertex1.pos.z && vertex2.pos.z <= vertex3.pos.z)
	{
		box.rangeZ.start = vertex2.pos.z;
	}
	else
	{
		box.rangeZ.start = vertex3.pos.z;
	}

	if(vertex1.pos.z >= vertex2.pos.z && vertex1.pos.z >= vertex3.pos.z)
	{
		box.rangeZ.end = vertex1.pos.z;
	}
	else if(vertex2.pos.z >= vertex1.pos.z && vertex2.pos.z >= vertex3.pos.z)
	{
		box.rangeZ.end = vertex2.pos.z;
	}
	else
	{
		box.rangeZ.end = vertex3.pos.z;
	}

	return box;
}
/****************************************************************************/
/*!
\brief
Returns the polygon's normal
*/
/****************************************************************************/
Vector3 Polygonn::GetNormal() const
{
	Vector3 normal = GetEdge1().Cross(GetEdge2());
	if(normal.IsZero())
	{
		return normal;
	}
	return normal.Normalized();
}
/****************************************************************************/
/*!
\brief
Move the polygon along it's normal
\param displacement
		the offset to move the polygon with
*/
/****************************************************************************/
void Polygonn::MoveAlongNormalBy(const float displacement)
{
	Vector3 displacementVector = GetNormal() * displacement;

	vertex1.pos += displacementVector;
	vertex2.pos += displacementVector;
	vertex3.pos += displacementVector;
}
/****************************************************************************/
/*!
\brief
Returns a copy of itself flipped
*/
/****************************************************************************/
Polygonn Polygonn::Flipped() const
{
	return Polygonn(vertex1, vertex3, vertex2);
}
Vector3 Polygonn::GetEdge1() const
{
	return vertex2.pos - vertex1.pos;
}

Vector3 Polygonn::GetEdge2() const
{
	return vertex3.pos - vertex2.pos;
}

Vector3 Polygonn::GetEdge3() const
{
	return vertex1.pos - vertex3.pos;
}