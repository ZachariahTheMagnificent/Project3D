#include "GLMesh.h"
#include "Graphics.h"

GLMesh::GLMesh()
{
}

GLMesh::~GLMesh()
{
}

void GLMesh::Render(const Graphics* graphics, const Mtx44& projection, const Mtx44& view, const Mtx44& transform, const Material* material, const bool& lightingEnabled) const
{
	const Mtx44 modelView = view * transform;
	const Mtx44 mvp = projection * modelView;

	if(lightingEnabled)
	{
		graphics->EnableLighting(modelView, material);
	}
	else
	{
		graphics->DisableLighting();
	}
	
	graphics->BindMesh(this);
	graphics->BindTexture(material->texture);
	graphics->BindMatrix(mvp);

	glDrawArrays(GL_TRIANGLES, 0, GetSize()*3);
}

void GLMesh::Render(const Graphics* graphics, const Mtx44& projection, const Mtx44& view, const Mtx44& transform, const Material* material, const bool& lightingEnabled, const unsigned& offset, const unsigned& count) const
{
	const Mtx44 modelView = view * transform;
	const Mtx44 mvp = projection * modelView;

	if(lightingEnabled)
	{
		graphics->EnableLighting(modelView, material);
	}
	else
	{
		graphics->DisableLighting();
	}
	
	graphics->BindMesh(this);
	graphics->BindTexture(material->texture);
	graphics->BindMatrix(mvp);

	glDrawArrays(GL_TRIANGLES, offset, count);
}