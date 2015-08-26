#pragma once
#include "Font.h"
#include "Graphics.h"
#include <string>

class GLFont : public Font
{
public:
	GLFont(Graphics* graphics = NULL);
	virtual ~GLFont();

	virtual void Render(const std::string text, const Mtx44& projection, const Mtx44& view, const Mtx44& transform, const Color& color, const float& size) const;
	
	Graphics* graphics;
};