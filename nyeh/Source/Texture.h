#pragma once
#include "MyContainer.h"
#include "D4DColor.h"
#include "Mtx44.h"

class Graphics;

class Texture : public MyContainer<D4DColor>
{
public:
	Texture(const unsigned& width = 0, const unsigned& height = 0);
	virtual ~Texture();

	virtual void Render(const Graphics* graphics, const Mtx44& projection, const Mtx44& view, const Mtx44& model) const = 0;

	void SetDimensions(const unsigned& width, const unsigned& height);
	const unsigned& GetWidth() const;
	const unsigned& GetHeight() const;

private:
	unsigned width;
	unsigned height;
};