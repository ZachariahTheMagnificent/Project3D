#include "DoubleData.h"

DoubleData::DoubleData(double* doub)
	:
data(doub)
{
}

std::ostream& DoubleData::PrintInfo(std::ostream& string) const
{
	return string << *data;
}

DoubleData::~DoubleData()
{
}