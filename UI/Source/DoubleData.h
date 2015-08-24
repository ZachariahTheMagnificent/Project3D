#pragma once
#include "UIData.h"

class DoubleData : public UIData
{
public:
	DoubleData(double* doub);
	~DoubleData();

	virtual std::ostream& PrintInfo(std::ostream& string) const;

private:
	double* data;
};