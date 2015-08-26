#pragma once
#include "UIDisplays.h"
#include "Font.h"
#include <string>

class UIText : public UIDisplays
{
public:
	UIText();
	virtual ~UIText();

	virtual UIBox GetBoundingBox() const;
	virtual void Render(const Mtx44& projection) const;

	std::string text;
	Color color;
	Font* font;
};