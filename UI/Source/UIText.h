#pragma once
#include "UIElement.h"
#include "D3DColor.h"
#include "UIDataClient.h"
#include <string>
#include <vector>

class UIText : public UIElement
{
public:
	static const unsigned DATA_SIZE = 10;
	UIText();
	virtual ~UIText();
	
	virtual void Update(const double& dt);
	UIBox GetBoundingBox() const;
	std::string GetText() const;

	void AddToEndOfText(const UIDataClient& data);

	Color color;
	unsigned spacing;
	std::vector<UIDataClient> data;
};