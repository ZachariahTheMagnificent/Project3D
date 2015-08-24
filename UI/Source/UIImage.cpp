#include "UIImage.h"

UIImage::UIImage()
	:
texture(NULL)
{
}

UIImage::~UIImage()
{
}

UIBox UIImage::GetBoundingBox() const
{
	return UIBox(Range<unsigned>(position.x, position.x + texture->GetWidth()*size), Range<unsigned>(position.y, position.y + texture->GetHeight()*size));
}

void UIImage::Update(const double& deltaTime)
{
}