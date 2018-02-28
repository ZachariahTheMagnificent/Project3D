#pragma once
#include "Mesh.h"

class Graphics;

class GLMesh : public Mesh
{
public:
	GLMesh();
	virtual ~GLMesh();

	virtual void Render(const Graphics* graphics, const Mtx44& projection, const Mtx44& view, const Mtx44& transform, const Material* material, const bool& lightingEnabled) const;
	virtual void Render(const Graphics* graphics, const Mtx44& projection, const Mtx44& view, const Mtx44& transform, const Material* material, const bool& lightingEnabled, const unsigned& offset, const unsigned& count) const;
};