#include "CharData.h"

CharData::CharData(char* character)
	:
data(character)
{
}

std::ostream& CharData::PrintInfo(std::ostream& string) const
{
	return string << *data;
}

CharData::~CharData()
{
}