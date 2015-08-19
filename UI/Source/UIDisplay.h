#pragma once
#include "UIElement.h"
#include "Texture.h"
#include "Vector2.h"

class UIDisplay : public UIElement
{
public:
	UIDisplay();
	~UIDisplay();

	Texture* texture;
	Vector2 position;
};