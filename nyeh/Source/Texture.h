#pragma once
#include <iostream>
#include "D4DColor.h"

class Texture
{
public:
	Texture(const unsigned& width = 0, const unsigned& height = 0);
	~Texture();
	void SetDimensions(const unsigned& width, const unsigned& height);
	const unsigned& GetWidth() const;
	const unsigned& GetHeight() const;
	D4DColor* GetBuffer();

private:
	D4DColor* buffer;
	unsigned width;
	unsigned height;
};