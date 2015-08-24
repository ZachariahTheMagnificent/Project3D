#pragma once
#include "UIElement.h"
#include "D3DColor.h"
#include "UIDataClient.h"
#include <string>

class UIText : public UIElement
{
public:
	UIText();
	virtual ~UIText();

	UIBox GetBoundingBox() const;
	std::string GetText() const;

	void AddToEndOfText(const UIDataClient& data);

	Color color;
	unsigned spacing;
};