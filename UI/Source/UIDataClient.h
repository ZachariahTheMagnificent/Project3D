#pragma once
#include "UIData.h"
#include <Vector3.h>

class UIDataClient
{
public:
	UIDataClient();
	~UIDataClient();

	UIDataClient(const UIDataClient& data);
	void operator=(const UIDataClient& data);

	UIDataClient(std::string* string);
	UIDataClient(double* doub);
	UIDataClient(Vector3* vec);
	UIDataClient(float* flt);
	UIDataClient(unsigned* uns);
	UIDataClient(int* integer);
	UIDataClient(char* character);
	
	void Set(std::string* string);
	void Set(double* doub);
	void Set(Vector3* vec);
	void Set(float* flt);
	void Set(unsigned* uns);
	void Set(int* integer);
	void Set(char* character);

	friend std::ostream& operator<<(std::ostream& string, const UIDataClient& data);

private:
	UIData* actualData;
};