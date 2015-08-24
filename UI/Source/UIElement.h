#pragma once
#include "Vector2.h"
#include "BoundingBox2D.h"

#define UIBox BoundingBox2D<unsigned>

class UIElement
{
public:
	UIElement();
	virtual ~UIElement();

	virtual void Update() = 0;
	virtual UIBox GetBoundingBox() const = 0;

	float size;
	Vector2 position;
	bool active;
	bool isUsed;
};