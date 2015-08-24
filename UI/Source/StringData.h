#pragma once
#include "UIData.h"
#include <string>

class StringData : public UIData
{
public:
	StringData(std::string* string);
	virtual ~StringData();

	virtual std::ostream& PrintInfo(std::ostream& string) const;

private:
	std::string* data;
};