#include "UnsignedData.h"

UnsignedData::UnsignedData(unsigned* uns)
	:
data(uns)
{
}

std::ostream& UnsignedData::PrintInfo(std::ostream& string) const
{
	return string << *data;
}

UnsignedData::~UnsignedData()
{
}