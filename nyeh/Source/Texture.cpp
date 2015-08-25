#include "Texture.h"

Texture::Texture(const unsigned& width, const unsigned& height)
	:
width(width),
height(height)
{
	const unsigned nPixels = width * height;
	
	SetSize(nPixels);
}

Texture::~Texture()
{
}

void Texture::SetDimensions(const unsigned& width, const unsigned& height)
{
	//skip function if we are already the appropriate size
	if(this->width == width && this->height == height)
	{
		return;
	}

	this->width = width;
	this->height = height;
	
	const unsigned nPixels = width * height;

	SetSize(nPixels);
}

const unsigned& Texture::GetWidth() const
{
	return width;
}

const unsigned& Texture::GetHeight() const
{
	return height;
}