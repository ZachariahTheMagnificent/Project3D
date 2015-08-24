#pragma once
#include "UIElement.h"
#include "Texture.h"

class UIImage : public UIElement
{
public:
	UIImage();
	virtual ~UIImage();

	UIBox GetBoundingBox() const;
	void Update(const double& deltaTime);

	Texture const* texture;
};