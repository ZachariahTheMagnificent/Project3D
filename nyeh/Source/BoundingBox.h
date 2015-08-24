#pragma once
#include "Vector3.h"
#include "Range.h"

template <class t = int>
class BoundingBox
{
public:
	BoundingBox(const Range<t>& rangeX = Range<t>(), const Range<t>& rangeY = Range<t>(), const Range<t>& rangeZ = Range<t>());
	~BoundingBox();

	void ResizeToFit(const BoundingBox<t>& box);

	t GetVolume() const;
	Vector3 GetDistanceFrom(const BoundingBox<t>& box) const;
	Vector3 GetDisplacement() const;

	bool IsInside(const Vector3& point) const;
	bool IsOverlapping(const BoundingBox<t>& box) const;
	bool IsBehind(const BoundingBox<t>& box) const;
	bool IsInFrontOf(const BoundingBox<t>& box) const;
	bool IsToTheLeftOf(const BoundingBox<t>& box) const;
	bool IsToTheRightOf(const BoundingBox<t>& box) const;
	bool IsAbove(const BoundingBox<t>& box) const;
	bool IsBelow(const BoundingBox<t>& box) const;

	Range<t> rangeX;
	Range<t> rangeY;
	Range<t> rangeZ;
};

template <class t>
BoundingBox<t>::BoundingBox(const Range<t>& rangeX, const Range<t>& rangeY, const Range<t>& rangeZ)
	:
rangeX(rangeX),
rangeY(rangeY),
rangeZ(rangeZ)
{
}

template <class t>
BoundingBox<t>::~BoundingBox()
{
}

template <class t>
void BoundingBox<t>::ResizeToFit(const BoundingBox<t>& box)
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
	
	if(box.rangeZ.start < rangeZ.start)
	{
		rangeZ.start = box.rangeZ.start;
	}
	if(box.rangeZ.end > rangeZ.end)
	{
		rangeZ.end = box.rangeZ.end;
	}
}

template <class t>
bool BoundingBox<t>::IsInside(const Vector3& point) const
{
	return rangeX.IsInRange(point.x) &&
		rangeY.IsInRange(point.y) &&
		rangeZ.IsInRange(point.z);
}

template <class t>
bool BoundingBox<t>::IsOverlapping(const BoundingBox<t>& box) const
{
	return rangeX.IsInRange(box.rangeX) &&
		rangeY.IsInRange(box.rangeY) &&
		rangeZ.IsInRange(box.rangeZ);
}

template <class t>
t BoundingBox<t>::GetVolume() const
{
	return rangeX.Length() * rangeY.Length() * rangeZ.Length();
}

template <class t>
bool BoundingBox<t>::IsBehind(const BoundingBox<t>& box) const
{
	return IsNegative(GetDistanceFrom(box).z);
}

template <class t>
bool BoundingBox<t>::IsInFrontOf(const BoundingBox<t>& box) const
{
	return !IsBehind(box);
}

template <class t>
bool BoundingBox<t>::IsToTheLeftOf(const BoundingBox<t>& box) const
{
	 return IsNegative(GetDistanceFrom(box).x);
}

template <class t>
bool BoundingBox<t>::IsToTheRightOf(const BoundingBox<t>& box) const
{
	return !IsToTheLeftOf(box);
}

template <class t>
bool BoundingBox<t>::IsBelow(const BoundingBox<t>& box) const
{
	return IsNegative(GetDistanceFrom(box).y);
}

template <class t>
bool BoundingBox<t>::IsAbove(const BoundingBox<t>& box) const
{
	return !IsBelow(box);
}

template <class t>
Vector3 BoundingBox<t>::GetDistanceFrom(const BoundingBox<t>& box) const
{
	return Vector3(rangeX.MidPoint() - box.rangeX.MidPoint(), rangeY.MidPoint() - box.rangeY.MidPoint(), rangeZ.MidPoint() - box.rangeZ.MidPoint());
}

template <class t>
Vector3 BoundingBox<t>::GetDisplacement() const
{
	return Vector3(rangeX.start, rangeY.start, rangeZ.start);
}