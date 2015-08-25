#pragma once
#include "MyContainer.h"
#include "D4DColor.h"

class Texture : public MyContainer<D4DColor>
{
public:
	Texture(const unsigned& width = 0, const unsigned& height = 0);
	virtual ~Texture();

	void SetDimensions(const unsigned& width, const unsigned& height);
	const unsigned& GetWidth() const;
	const unsigned& GetHeight() const;

private:
	unsigned width;
	unsigned height;
};