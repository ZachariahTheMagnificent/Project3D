#include "GLFont.h"

GLFont::GLFont(Graphics* graphics)
	:
graphics(graphics)
{
}

GLFont::~GLFont()
{
}

void GLFont::Render(const std::string text, const Mtx44& projection, const Mtx44& view, const Mtx44& transform, const Color& color, const float& size) const
{
	if(mesh == NULL) //Proper error check
	{
		return;
	}

	//glDisable(GL_DEPTH_TEST);
	graphics->EnableText(color);
	
	const Material material(Color(), Color(), Color(), 0, font);

	for(unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * spacing, 0, 0);

		const Mtx44 model = transform * characterSpacing;
		
		const unsigned numofverts = 6;
		//mesh->Render(projection, view, model, &material, false, (unsigned)text[i] * numofverts, numofverts);
	}

	graphics->DisableText();
	//glEnable(GL_DEPTH_TEST);
}