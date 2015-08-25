#include "UIElementFactory.h"
#include <iostream>

UIElementFactory::UIElementFactory()
{
}

UIElementFactory::~UIElementFactory()
{
}

//UIText* UIElementFactory::GetText()
//{
//	return textProduction.GetInstance();
//}

//UIImage* UIElementFactory::GetImage()
//{
//	return imageProduction.GetInstance();
//}

void UIElementFactory::UpdateAllElements(const double& deltaTime)
{
	//for(UIText* text = textProduction.GetBegin(), *end = textProduction.GetEnd(); text != end; ++text)
	//{
	//	text->Update(deltaTime);
	//}

	//for(UIImage* image = imageProduction.GetBegin(), *end = imageProduction.GetEnd(); image != end; ++image)
	//{
	//	image->Update(deltaTime);
	//}
}