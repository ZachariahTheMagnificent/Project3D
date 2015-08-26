#include "UIImage.h"

UIImage::UIImage()
	:
image(NULL)
{
}

UIImage::~UIImage()
{
}

UIBox UIImage::GetBoundingBox() const
{
	return UIBox(Range<unsigned int>(transform.translate.x, transform.translate.x + image->GetWidth()*transform.scale.x), Range<unsigned int>(transform.translate.y, transform.translate.y + image->GetHeight()*transform.scale.y));
}

void UIImage::Render(const Mtx44& projection) const
{
	if(active)
	{
		Mtx44 view;
		view.SetToIdentity();
		image->Render(projection, view, transform.Matrix());
	}
}