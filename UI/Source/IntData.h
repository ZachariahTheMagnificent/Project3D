#pragma once
#include "UIData.h"

class IntData : public UIData
{
public:
	IntData(int* integer);
	~IntData();

	virtual std::ostream& PrintInfo(std::ostream& string) const;

private:
	int* data;
};