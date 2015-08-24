#pragma once
#include "UIData.h"

class FloatData : public UIData
{
public:
	FloatData(float* flt);
	~FloatData();

	virtual std::ostream& PrintInfo(std::ostream& string) const;

private:
	float* data;
};