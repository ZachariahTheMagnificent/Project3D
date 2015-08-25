#pragma once
#include "UIData.h"
#include "Vector3.h"

class VectorData : public UIData
{
public:
	VectorData(Vector3* vec);
	virtual ~VectorData();

	virtual std::ostream& PrintInfo(std::ostream& string) const;

private:
	Vector3* data;
};