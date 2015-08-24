#pragma once
#include <sstream>

class UIData
{
public:
	UIData();
	virtual ~UIData();

	virtual std::ostream& PrintInfo(std::ostream& string) const = 0;
};