#pragma once
#include "UIData.h"

class CharData : public UIData
{
public:
	CharData(char* character);
	~CharData();
	
	virtual std::ostream& PrintInfo(std::ostream& string) const;

private:
	char* data;
};