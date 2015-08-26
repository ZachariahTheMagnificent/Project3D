#include "UIDisplaysFactory.h"

UIDisplaysFactory::UIDisplaysFactory()
{
}

UIDisplaysFactory::~UIDisplaysFactory()
{
}

UIMesh* UIDisplaysFactory::GetMesh()
{
	return meshProduction.GetInstance();
}

UIText* UIDisplaysFactory::GetText()
{
	return textProduction.GetInstance();
}

UIImage* UIDisplaysFactory::GetImage()
{
	return imageProduction.GetInstance();
}

void UIDisplaysFactory::Render(const Mtx44& projection)
{
	for(UIMesh const* mesh = meshProduction.GetBegin(), *end = meshProduction.GetEnd(); mesh != end; ++mesh)
	{
		mesh->Render(projection);
	}

	for(UIImage const* image = imageProduction.GetBegin(), *end = imageProduction.GetEnd(); image != end; ++image)
	{
		image->Render(projection);
	}

	for(UIText const* text = textProduction.GetBegin(), *end = textProduction.GetEnd(); text != end; ++text)
	{
		text->Render(projection);
	}
}