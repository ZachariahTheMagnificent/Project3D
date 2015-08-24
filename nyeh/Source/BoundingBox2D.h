#pragma once
#include "Vector2.h"
#include "Range.h"

template <class t = int>
class BoundingBox2D
{
public:
	BoundingBox2D(const Range<t>& rangeX = Range<t>(), const Range<t>& rangeY = Range<t>());
	~BoundingBox2D();

	void ResizeToFit(const BoundingBox2D<t>& box);

	t GetArea() const;
	Vector2 GetDistanceFrom(const BoundingBox2D<t>& box) const;
	Vector2 GetDisplacement() const;
	
	bool IsInside(const Vector2& point) const;
	bool IsOverlapping(const BoundingBox2D<t>& box) const;
	bool IsToTheLeftOf(const BoundingBox2D<t>& box) const;
	bool IsToTheRightOf(const BoundingBox2D<t>& box) const;
	bool IsAbove(const BoundingBox2D<t>& box) const;
	bool IsBelow(const BoundingBox2D<t>& box) const;

	Range<t> rangeX;
	Range<t> rangeY;
};

template <class t>
BoundingBox2D<t>::BoundingBox2D(const Range<t>& rangeX, const Range<t>& rangeY)
	:
rangeX(rangeX),
rangeY(rangeY)
{
}

template <class t>
BoundingBox2D<t>::~BoundingBox2D()
{
}

template <class t>
void BoundingBox2D<t>::ResizeToFit(const BoundingBox2D<t>& box)
{
	if(box.rangeX.start < rangeX.start)
	{
		rangeX.start = box.rangeX.start;
	}
	if(box.rangeX.end > rangeX.end)
	{
		rangeX.end = box.rangeX.end;
	}
	
	if(box.rangeY.start < rangeY.start)
	{
		rangeY.start = box.rangeY.start;
	}
	if(box.rangeY.end > rangeY.end)
	{
		rangeY.end = box.rangeY.end;
	}
}

template <class t>
bool BoundingBox2D<t>::IsInside(const Vector2& point) const
{
	return rangeX.IsInRange(point.x) &&
		rangeY.IsInRange(point.y);
}

template <class t>
bool BoundingBox2D<t>::IsOverlapping(const BoundingBox2D<t>& box) const
{
	return rangeX.IsInRange(box.rangeX) &&
		rangeY.IsInRange(box.rangeY);
}

template <class t>
t BoundingBox2D<t>::GetArea() const
{
	return rangeX.Length() * rangeY.Length();
}

template <class t>
bool BoundingBox2D<t>::IsToTheLeftOf(const BoundingBox2D<t>& box) const
{
	 return IsNegative(GetDistanceFrom(box).x);
}

template <class t>
bool BoundingBox2D<t>::IsToTheRightOf(const BoundingBox2D<t>& box) const
{
	return !IsToTheLeftOf(box);
}

template <class t>
bool BoundingBox2D<t>::IsBelow(const BoundingBox2D<t>& box) const
{
	return IsNegative(GetDistanceFrom(box).y);
}

template <class t>
bool BoundingBox2D<t>::IsAbove(const BoundingBox2D<t>& box) const
{
	return !IsBelow(box);
}

template <class t>
Vector2 BoundingBox2D<t>::GetDistanceFrom(const BoundingBox2D<t>& box) const
{
	return Vector3(rangeX.MidPoint() - box.rangeX.MidPoint(), rangeY.MidPoint() - box.rangeY.MidPoint());
}

template <class t>
Vector2 BoundingBox2D<t>::GetDisplacement() const
{
	return Vector2(rangeX.start, rangeY.start);
}