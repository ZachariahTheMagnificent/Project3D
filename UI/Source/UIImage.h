#pragma once
#include "UIElement.h"
#include "Texture.h"

class UIImage : public UIElement
{
public:
	UIImage();
	virtual ~UIImage();

	UIBox GetBoundingBox() const;

	Texture const* texture;
};