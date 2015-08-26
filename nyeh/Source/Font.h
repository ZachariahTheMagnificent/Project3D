#pragma once
#include "Mesh.h"
#include "D3DColor.h"
#include "Texture.h"

class Font
{
public:
	Font();
	virtual ~Font();

	virtual void Render(const std::string text, const Mtx44& projection, const Mtx44& view, const Mtx44& transform, const Color& color, const float& size) const = 0;

	Mesh const* mesh;
	Texture const* font;
	float spacing;
};