#pragma once
#include "UIDisplays.h"
#include "Texture.h"

class UIImage : public UIDisplays
{
public:
	UIImage();
	virtual ~UIImage();

	virtual UIBox GetBoundingBox() const;
	virtual void Render(const Mtx44& projection) const;

	Texture* image;
};

