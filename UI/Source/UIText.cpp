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
	std::stringstream text;

	for(std::vector<UIDataClient>::const_iterator it = data.begin(), end = data.end(); it != end; ++it)
	{
		text << *it;
	}

	return text.str();
}

void UIText::AddToEndOfText(const UIDataClient& data)
{
	this->data.push_back(data);
}

void UIText::Update(const double& dt)
{
}