#include "IntData.h"

IntData::IntData(int* integer)
	:
data(integer)
{
}

std::ostream& IntData::PrintInfo(std::ostream& string) const
{
	return string << *data;
}

IntData::~IntData()
{
}