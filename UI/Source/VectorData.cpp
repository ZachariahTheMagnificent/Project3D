#include "VectorData.h"

VectorData::VectorData(Vector3* vec)
	:
data(vec)
{
}

VectorData::~VectorData()
{
}

std::ostream& VectorData::PrintInfo(std::ostream& string) const
{
	return string << '[' << data->x << ", " << data->y << ", " << data->z << ']';
}