#include "UIText.h"
#include "D3DColor.h"
#include <string>

UIText::UIText()
	:
spacing(0)
{
}

UIText::~UIText()
{
}

UIBox UIText::GetBoundingBox() const
{
	const std::string text = GetText();
	const unsigned textLength = text.size();

	//Y will be zero if textLength is 0
	return UIBox(Range<unsigned>(position.x, position.x + (size + spacing)*textLength), Range<unsigned>(position.y, position.y + size*(textLength > 0)));
}

std::string UIText::GetText() const
{
	std::string text;
	return text;
}