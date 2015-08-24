#pragma once
#include "UIData.h"

class IntData : public UIData
{
public:
	IntData(int* integer);
	virtual ~IntData();

	virtual std::ostream& PrintInfo(std::ostream& string) const;

private:
	int* data;
};