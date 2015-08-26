#include "UIText.h"

UIText::UIText()
	:
font(NULL)
{
}

UIText::~UIText()
{
}

UIBox UIText::GetBoundingBox() const
{
	const unsigned length = text.length();
	const unsigned charLength = length + font->spacing;
	return UIBox(Range<unsigned int>(transform.translate.x, transform.translate.x + charLength*transform.scale.x), Range<unsigned int>(transform.translate.y, transform.translate.y + charLength*transform.scale.y));
}

void UIText::Render(const Mtx44& projection) const
{
	if(active)
	{
		Mtx44 view;
		view.SetToIdentity();
		font->Render(text, projection, view, transform.Matrix(), color, 5);
	}
}