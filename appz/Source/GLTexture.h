#pragma once
#include "Texture.h"

class Graphics;

class GLTexture : public Texture
{
public:
	GLTexture(Graphics* graphics = NULL);
	virtual ~GLTexture();
	
	virtual void Render(const Mtx44& projection, const Mtx44& view, const Mtx44& model) const;

	Graphics* graphics;
};