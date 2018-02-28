#include "GLTexture.h"
#include "Graphics.h"

GLTexture::GLTexture(Graphics* graphics)
{
}

GLTexture::~GLTexture()
{
}

void GLTexture::Render(const Graphics* graphics, const Mtx44& projection, const Mtx44& view, const Mtx44& model) const
{
	const Mesh* mesh = graphics->GetRenderingPlane();

	const Material material(Color(), Color(), Color(), 0, this);

	//mesh->Render(projection, view, model, &material, false);
}