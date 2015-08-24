#include "FloatData.h"

FloatData::FloatData(float* flt)
	:
data(flt)
{
}

std::ostream& FloatData::PrintInfo(std::ostream& string) const
{
	return string << *data;
}

FloatData::~FloatData()
{
}