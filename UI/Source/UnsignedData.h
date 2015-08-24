#pragma once
#include "UIData.h"

class UnsignedData : public UIData
{
public:
	UnsignedData(unsigned* uns);
	virtual ~UnsignedData();

	virtual std::ostream& PrintInfo(std::ostream& string) const;

private:
	unsigned* data;
};