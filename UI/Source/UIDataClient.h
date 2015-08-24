#pragma once
#include "UIData.h"

class UIDataClient
{
public:
	UIDataClient(std::string* string);
	UIDataClient(double* doub);
	UIDataClient(float* flt);
	UIDataClient(unsigned* uns);
	UIDataClient(int* integer);
	UIDataClient(char* character);
	~UIDataClient();

	friend std::ostream& operator<<(std::ostream& string, const UIDataClient& data);
private:
	UIData* actualData;
};