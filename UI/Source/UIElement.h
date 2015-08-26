#pragma once
#include "Vector2.h"
#include "BoundingBox2D.h"
#include "Trigger.h"

typedef BoundingBox2D<unsigned> UIBox;

class UIElement : public Trigger
{
public:
	UIElement();
	virtual ~UIElement();

	virtual void Update(const double& deltaTime) = 0;
	virtual UIBox GetBoundingBox() const = 0;
	virtual bool HasTriggered() = 0;

	bool active;
	bool isUsed;
};