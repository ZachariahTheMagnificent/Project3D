#include "Texture.h"

Texture::Texture(const unsigned& width, const unsigned& height)
	:
width(width),
height(height),
buffer(NULL)
{
	unsigned nPixels = width * height;
	if(nPixels)
	{
		buffer = new D4DColor[nPixels];
	}
}

Texture::~Texture()
{
	if(buffer)
	{
		delete [] buffer;
		buffer = NULL;
	}
}

void Texture::SetDimensions(const unsigned& width, const unsigned& height)
{
	if(this->width == width && this->height == height)
	{
		return;
	}
	this->width = width;
	this->height = height;
	if(buffer)
	{
		delete [] buffer;
		buffer = NULL;
	}
	unsigned nPixels = width * height;
	if(nPixels)
	{
		buffer = new D4DColor[nPixels];
	}
}

const unsigned& Texture::GetWidth() const
{
	return width;
}

const unsigned& Texture::GetHeight() const
{
	return height;
}

D4DColor* Texture::GetBuffer()
{
	return buffer;
}