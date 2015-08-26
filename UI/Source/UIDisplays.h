#pragma once
#include "UIElement.h"
#include "Transformation.h"

class UIDisplays
{
public:
	UIDisplays();
	virtual ~UIDisplays();

	virtual UIBox GetBoundingBox() const = 0;
	virtual void Render(const Mtx44& projection) const = 0;

	Transformation transform;
	bool active;
	bool isUsed;
};