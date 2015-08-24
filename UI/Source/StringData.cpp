#include "StringData.h"

StringData::StringData(std::string* string)
	:
data(string)
{
}

std::ostream& StringData::PrintInfo(std::ostream& string) const
{
	return string << *data;
}

StringData::~StringData()
{
}